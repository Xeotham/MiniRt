#================ COMPILATOR ================#
CC = cc
#=================== FLAGS ==================#
FLAGS = -Wall -Wextra -Werror -gdwarf-4
#=================== NAME ===================#
NAME = miniRT
#============ MINISHELL SOURCES =============#
SRCS = \
	main.c \
	parser/get_map.c \
	parser/link_list/create_list.c\
	parser/link_list/obj_list_utils.c\
	vector/vector.c \
	vector/vector_math.c \
#============ TRANSFORM .c TO .o ============#
LIBFT = libft/libft.a
LIBMLX = MLX42
OBJ_DIR = obj/
SRCS_DIR = srcs/
INCLUDE_DIR = includes
MLX_INCLUDE = MLX42/includes
OBJ = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
INCLUDES = -I$(INCLUDE_DIR) -I$(MLX_INCLUDE)

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
	@ $(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME) : $(LIBFT) $(OBJ)
	@ $(CC) $(OBJ) $(LIBFT) -o $(NAME)

clean :
	@ $(MAKE) -C libft clean --no-print-directory
	@ rm -rf $(OBJ_DIR)

fclean :
	@ $(MAKE) -C libft fclean --no-print-directory
	@ rm -rf $(NAME) $(OBJ_DIR) MLX42

re : fclean all

.PHONY : all clean fclean re
