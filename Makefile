#================ COMPILATOR ================#
CC = cc
#=================== FLAGS ==================#
FLAGS = -Wall -Wextra -Werror -gdwarf-4
#=================== NAME ===================#
NAME = miniRT
#============ MINISHELL SOURCES =============#
SRCS = \
	parser/get_map.c \
	main.c
#============ TRANSFORM .c TO .o ============#
LIBFT = libft/libft.a
OBJ_DIR = obj/
SRCS_DIR = srcs/
INCLUDE_DIR = includes
OBJ = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
INCLUDES = -I$(INCLUDE_DIR)

all : $(NAME)

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
	@ rm -rf $(NAME) $(OBJ_DIR)

re : fclean all

.PHONY : all clean fclean re
