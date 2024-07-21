#================ COMPILATOR ================#
CC = cc
#=================== FLAGS ==================#
FLAGS = -Wall -Wextra -Werror -g -Ofast
DEBUG_FLAGS = -Wall -Wextra -Werror -g
#=================== NAME ===================#
NAME = miniRT
#============ MINISHELL SOURCES =============#
SRCS = \
	main.c \
	error.c \
	draw_scene.c \
	color.c \
	parser/create_scene.c \
	parser/element_list_utils.c \
	parser/format.c \
	vector/vector.c \
	vector/vector_math.c \
	matrix/matrix.c \
	matrix/matrix_product.c \
	matrix/transform_matrix.c \
	elements/create_light.c \
	elements/create_plane.c \
	elements/create_sphere.c \
	elements/create_camera.c \
	elements/create_cylinder.c \
	Ray/ray.c \
	intersection_test/sphere.c \
	intersection_test/intersection_utils.c
#============ TRANSFORM .c TO .o ============#
MLX_DIR = MLX42
OBJ_DIR = obj/
SRCS_DIR = srcs/
INCLUDE_DIR = includes
MLX_INCLUDE = $(MLX_DIR)/include/MLX42
OBJ = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
INCLUDES = -I$(INCLUDE_DIR) -I$(MLX_INCLUDE) -Ilibft/include
LIBFT = libft/libft.a
LIBMLX = $(MLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm
TEST_SCENE = test.rt
V_FLAGS = --leak-check=full --show-leak-kinds=all --track-fds=yes

all : libmlx $(NAME)

libmlx:
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "Directory $(MLX_DIR) does not exist. Cloning the repository..."; \
		git clone https://github.com/codam-coding-college/MLX42.git $(MLX_DIR); \
    fi
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build
	@make -C $(MLX_DIR)/build --no-print-directory -j$(nproc)

$(LIBFT) :
	@ $(MAKE) -C libft all --no-print-directory

$(OBJ_DIR)%.o : $(SRCS_DIR)%.c
	@ mkdir -p $(dir $@)
	@ $(CC) $(DEBUG_FLAGS) $(INCLUDES) -c $< -o $@

$(NAME) : $(LIBFT) $(OBJ)
	@ $(CC) $(DEBUG_FLAGS) $(OBJ) -o $(NAME) $(LIBFT) $(LIBMLX)
	@ echo "miniRT Compiled !"

run : all
	@ ./$(NAME) $(TEST_SCENE)

gdb : all
	@ gdb --tui $(NAME) -ex 'start $(TEST_SCENE)'

valgrind : all
	@ valgrind $(V_FLAGS) ./$(NAME) $(TEST_SCENE)

clean :
	@ $(MAKE) -C libft clean --no-print-directory
	@ rm -rf $(OBJ_DIR)

fclean :
	@ $(MAKE) -C libft fclean --no-print-directory
	@ rm -rf $(NAME) $(OBJ_DIR) $(MLX_DIR)

re : fclean all

new : clean all

.PHONY : all clean fclean re run gdb valgrind new
