# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgrea <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/23 22:44:38 by fgrea             #+#    #+#              #
#    Updated: 2017/01/23 16:44:19 by fgrea            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Werror -Wextra

SRC = main.c fillit_is_valid.c fillit_size_map.c fillit_createtettab.c \
	  fillit_newtetlist.c fillit_read_file.c \
	  fillit_put_tet.c ft_putnbrendl.c fillit_reduce_tet.c fillit_lstpast.c \
	  fillit_algorythm.c

SRC2 = $(subst .c,.o,$(SRC))


$(NAME): lib $(SRC2)
		echo $(SRC2)
		gcc $(FLAGS) -o $(NAME) $(SRC2) -L libft -lft

$(SRC2):
		gcc $(FLAGS) -c $(SRC) -Iincludes/ -Ilibft/includes/

all: $(NAME)

lib:
	make -C libft

clean:
	/bin/rm -rf $(SRC2)
	make -C libft clean

fclean: clean
	/bin/rm -rf $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: clean fclean all re
