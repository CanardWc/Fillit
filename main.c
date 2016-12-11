/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:42:16 by fgrea             #+#    #+#             */
/*   Updated: 2016/12/10 22:28:06 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	size_t	x;
	t_list	*ntl;
	char	**map;
	size_t	j;

	map = NULL;
	x = 0;
	j = 0;
	argc = 2;								//a virer pour mettre la merde style cp
	fd = open(argv[1], O_RDONLY);
	ntl = fillit_read_file(fd);
	ntl = fillit_lstpast(ntl);
	map = fillit_algorythm(ntl, x);
	while (map[j])
	{
		ft_putendl(map[j]);
		j++;
	}
	return (0);
}
