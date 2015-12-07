# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/25 11:22:31 by pdelefos          #+#    #+#              #
#    Updated: 2015/08/27 17:59:14 by pdelefos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRC = main.c ft_check_error.c ft_fuck.c ft_create_grid.c ft_list.c ft_resolve.c ft_make_square.c ft_saruman.c ft_print_bsq.c ft_strdup.c ft_get_grid.c ft_sauron.c

SRCO = main.o ft_check_error.o ft_fuck.o ft_create_grid.o ft_list.o ft_resolve.o ft_make_square.o ft_saruman.o ft_print_bsq.o ft_strdup.o ft_get_grid.o ft_sauron.o

LIB = libft.a

all : $(NAME)

$(NAME) :
	gcc -c $(SRC)
	gcc -Wall -Wextra -Werror $(SRCO) $(LIB) -o $(NAME)

clean :
	rm -f $(SRCO)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re
