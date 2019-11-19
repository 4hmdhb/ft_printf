# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: basylbek <basylbek@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/11 14:11:15 by basylbek          #+#    #+#              #
#    Updated: 2019/11/11 14:22:24 by basylbek         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang

NAME = libft.a

FLAGS = -Wall -Wextra -Werror -O2

HEADER = libft.h

LIBFILES = $(SRC:.c=.o)

SRC = ft_isdigit.c \
	  ft_itoa_precision.c \
	  ft_itoa.c \
	  ft_numlen.c \
	  ft_pow.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_strchr.c \
	  ft_strdel.c \
	  ft_strdup.c \
	  ft_strjoin.c \
	  ft_strlen.c \
	  ft_strnew.c \
	  ft_strstr.c \
	  ft_toupper.c \
	  ft_atoi.c \
	  ft_isspace.c \
	  ft_strncpy.c

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SRC) -I $(HEADER)
	@ar rc $(NAME) $(LIBFILES)
	@ranlib $(NAME)

clean:
	@rm -f $(LIBFILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
