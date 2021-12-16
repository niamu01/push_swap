# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 00:28:26 by yeju              #+#    #+#              #
#    Updated: 2021/10/08 02:17:20 by yeju             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC =	ft_atoi.c ft_isdigit.c ft_isspace.c ft_lstadd_back.c ft_lstadd_front.c \
		ft_lstclear.c ft_lstdelone.c ft_lstnew.c ft_lstsize.c ft_memcmp.c \
		ft_memcpy.c ft_nbrlen.c ft_putchar_fd.c ft_putnbr_base_fd.c ft_putnchar_fd.c \
		ft_putstr_fd.c ft_strchr.c ft_strlen.c

OBJ =	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $^

$(OBJ): $(SRC)
	@$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
