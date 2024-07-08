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
	utils.c \
	parser/create_scene.c \
	parser/create_list.c \
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
#============ TRANSFORM .c TO .o ============#
LIBFT = libft/libft.a
LIBMLX = MLX42
OBJ_DIR = obj/
SRCS_DIR = srcs/
INCLUDE_DIR = includes
MLX_INCLUDE = MLX42/include/MLX42
OBJ = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
INCLUDES = -I$(INCLUDE_DIR) -I$(MLX_INCLUDE) -Ilibft/include
TEST_SCENE = test.rt
V_FLAGS = --leak-check=full --show-leak-kinds=all --track-fds=yes

all : libmlx $(NAME)

libmlx:
	@if [ ! -d "$(LIBMLX)" ]; then \
		echo "Directory $(LIBMLX) does not exist. Cloning the repository..."; \
		git clone https://github.com/codam-coding-college/MLX42.git; \
    fi
	@cmake $(LIBMLX) -B $(LIBMLX)/build
	@make -C $(LIBMLX)/build --no-print-directory -j$(nproc)

$(LIBFT) :
	@ $(MAKE) -C libft all --no-print-directory

$(OBJ_DIR)%.o : $(SRCS_DIR)%.c
	@ mkdir -p $(dir $@)
	@ $(CC) $(DEBUG_FLAGS) $(INCLUDES) -c $< -o $@

$(NAME) : $(LIBFT) $(OBJ)
	@ $(CC) $(DEBUG_FLAGS) $(OBJ) $(LIBFT) -lm -o $(NAME)
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
	@ rm -rf $(NAME) $(OBJ_DIR) MLX42

re : fclean all

.PHONY : all clean fclean re run gdb valgrind
