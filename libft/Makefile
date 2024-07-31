# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 15:55:46 by tde-la-r          #+#    #+#              #
#    Updated: 2024/07/28 18:38:02 by mhaouas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = get_next_line.c\
		  ft_printf.c\
		  ft_fprintf.c\
		  printf_args.c\
		  ft_atoi.c\
		  ft_atoi_radix.c\
		  ft_bzero.c\
		  ft_calloc.c\
		  ft_isalnum.c\
		  ft_isalpha.c\
		  ft_isascii.c\
		  ft_isbase.c\
		  ft_isdigit.c\
		  ft_islower.c\
		  ft_isupper.c\
		  ft_isprint.c\
		  ft_itoa.c\
		  ft_memchr.c\
		  ft_memcmp.c\
		  ft_memcpy.c\
		  ft_memmove.c\
		  ft_memset.c\
		  ft_putchar_fd.c\
		  ft_putendl_fd.c\
		  ft_putnbr_fd.c\
		  ft_putstr_fd.c\
		  ft_strchr.c\
		  ft_strdup.c\
		  ft_striteri.c\
		  ft_strmapi.c\
		  ft_strjoin.c\
		  ft_strlcpy.c\
		  ft_strlcat.c\
		  ft_strlen.c\
		  ft_strncmp.c\
		  ft_strnstr.c\
		  ft_strrchr.c\
		  ft_strtrim.c\
		  ft_split.c\
		  ft_substr.c\
		  ft_tolower.c\
		  ft_toupper.c\
		  ft_lstnew_bonus.c\
		  ft_lstadd_front_bonus.c\
		  ft_lstsize_bonus.c\
		  ft_lstlast_bonus.c\
		  ft_lstadd_back_bonus.c\
		  ft_lstdelone_bonus.c\
		  ft_lstclear_bonus.c\
		  ft_lstiter_bonus.c\
		  ft_lstmap_bonus.c\
		  ft_lower.c\
		  ft_superior.c\
		  ft_free_2d_array.c\
		  ft_atod.c\
		  ft_join_and_free.c\
		  ft_multi_free.c\
		  ft_array_len.c\
		  ft_close.c\
		  ft_destroy_ptr.c\
		  ft_strrncmp.c\
		  ft_numlen.c\

SRCS_DIR = sources/
OBJS_DIR = objects/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

INCLUDE_DIR = include/
INCLUDE = -Iinclude/

CC = clang
FLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "libft Compiled"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean :
	$(RM) $(OBJS_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
