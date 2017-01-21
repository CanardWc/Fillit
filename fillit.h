/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 21:09:47 by fgrea             #+#    #+#             */
/*   Updated: 2017/01/21 04:31:42 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include "libft/libft.h"

typedef struct		s_tet
{
	char			**tab;
	size_t			i;
	size_t			j;
	size_t			wdth;
	size_t			hght;
	size_t			swap;
	struct s_tet	*next;
	struct s_tet	*previous;
}					t_tet;

typedef struct		s_map
{
	char			**map;
	size_t			i;
	size_t			j;
}					t_map;

char				**fillit_algorythm(t_tet *ntl, size_t x);
t_tet				*fillit_lstpast(t_tet *ntl);
t_tet				*fillit_reduce_tet(t_tet *ntl);
char				**fillit_createtettab(char *tmp, char c);
char				**fillit_size_map(t_tet *ntl, size_t x);
size_t				fillit_put_tet(t_tet *ntl, t_map *p);
char				**fillit_erase_tet(t_tet *ntl, char **map);
int					fillit_is_valid(char *tet);
t_tet				*fillit_newtetslist(char *tmp, char c);
int					fillit_open_file(int argc, char **argv);
t_tet				*fillit_read_file(int fd);
void				ft_putnbrendl(int i);

#endif
