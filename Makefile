# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgrea <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/23 22:44:38 by fgrea             #+#    #+#              #
#    Updated: 2017/02/18 05:36:23 by fgrea            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Werror -Wextra

SRC = main.c fillit_is_valid.c fillit_size_map.c fillit_createtettab.c \
	  fillit_newtetlist.c fillit_read_file.c \
	  fillit_put_tet.c ft_putnbrendl.c fillit_reduce_tet.c fillit_lstpast.c \
	  fillit_algorythm.c

OBJ = $(SRC:.c=.o)


$(NAME): lib $(OBJ)
		echo $(OBJ)
		gcc $(FLAGS) -o $(NAME) $(OBJ) -L libft -lft

$(SRC2):
		gcc $(FLAGS) -c $(SRC) -Iincludes/ -Ilibft/includes/

all: $(NAME)

lib:
	make -C libft

clean:
	/bin/rm -rf $(OBJ)
	make -C libft clean

fclean: clean
	/bin/rm -rf $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: clean fclean all re
