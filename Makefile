# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oearlene <oearlene@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/08 20:13:00 by oearlene          #+#    #+#              #
#    Updated: 2020/10/17 15:07:16 by oearlene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_PATH = ./srcs/
INC_PATH = ./includes/
OBJ_PATH = ./obj/
LFT_PATH = ./libft/
LFT_OBJ_PATH = ./libft/obj/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I ,$(INC_PATH))
INC_LFT = $(addprefix -I ,$(LFT_PATH))
INC_H = $(addprefix $(INC_PATH),$(INC_NAME))
LFT = $(addprefix $(LFT_OBJ_PATH),$(LFT_OBJ_NAME))
LFT_H = $(addprefix $(LFT_PATH),$(LFT_H_NAME))

LFT_OBJ_NAME = *.o

OBJ_NAME = $(SRC_NAME:.c=.o)

LFT_H_NAME = libft.h

INC_NAME = ft_printf.h

SRC_NAME =  ft_printf.c \
            parser.c \
            print.c \
            print_nbr_conversions.c \
            print_numbers.c \
            print_hex_nb.c \
            get_conv_f.c \
            print_strings.c

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LFT_PATH)
	ar rc $(NAME) $(OBJ) $(INC_H) $(LFT) $(LFT_H)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	gcc $(FLAGS) $(INC) $(INC_LFT) -o $@ -c $<

clean:
	make -C $(LFT_PATH) clean
	rm -rf $(OBJ_PATH)

fclean: clean
	make -C $(LFT_PATH) fclean
	rm -f $(NAME)

re: fclean all