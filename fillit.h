/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 21:09:47 by fgrea             #+#    #+#             */
/*   Updated: 2016/12/10 21:04:54 by fgrea            ###   ########.fr       */
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

typedef struct		s_list
{
	char			**tab;
	size_t			i;
	size_t			j;
	size_t			wdth;
	size_t			hght;
	size_t			swap;
	struct s_list	*next;
	struct s_list	*previous;
}					t_list;

char		**fillit_algorythm(t_list *ntl, size_t x);
t_list		*fillit_lstpast(t_list *ntl);
t_list		*fillit_reduce_tet(t_list *ntl);
char		**fillit_createtettab(char *tmp, char c);
char		**fillit_size_map(t_list *ntl, size_t x);
size_t		fillit_put_tet(t_list *ntl, char **map);
int			fillit_is_valid(char *tet);
t_list		*fillit_newtetslist(char *tmp, char c);
int			fillit_open_file(int argc, char **argv);
t_list		*fillit_read_file(int fd);
void		ft_putnbrendl(int i);

#endif
