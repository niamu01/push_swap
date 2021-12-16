# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 00:55:17 by yeju              #+#    #+#              #
#    Updated: 2021/10/08 02:30:15 by yeju             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
CC = gcc
NAME = push_swap
LIBFT = libft/libft.a

SRC =	move_utils.c move_reduce.c move.c order.c order_utils.c \
			translate_utils.c stack_print.c main.c

OBJ = $(SRC:.c=.o) 

all: $(NAME)

$(NAME): $(OBJ) compile_libft
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFT)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $^

compile_libft:
	make all -C libft/

clean:
	rm -f $(OBJ)
	rm -f ${LIBFT}

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re compile_libft
