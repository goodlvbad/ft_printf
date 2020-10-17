# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oearlene <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/17 22:51:45 by oearlene          #+#    #+#              #
#    Updated: 2019/10/05 00:33:41 by oearlene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strlcat.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isalpha.c \
		ft_isalnum.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putnbr_fd.c \
		ft_putendl_fd.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putnbr.c \
		ft_putendl.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strnew.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_lstnew.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstmap.c \

OBJ = $(SRC:.c=.o)

OBJ_PATH = ./obj/

OBJ_1 = $(addprefix $(OBJ_PATH),$(OBJ))

HED = libft.h

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(OBJ_PATH)%.o: %.c
	@mkdir -p $(OBJ_PATH)
	@gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJ_1)
	@ar rc $(NAME) $(OBJ_1) $(HED)
	@ranlib $(NAME)

clean:
	@/bin/rm -rf $(OBJ_PATH)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all