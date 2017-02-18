/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:42:16 by fgrea             #+#    #+#             */
/*   Updated: 2017/02/06 13:57:03 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	size_t	x;
	t_tet	*ntl;
	char	**map;
	size_t	j;

	map = NULL;
	x = 0;
	j = 0;
	if (argc < 2)
	{
		ft_putendl("usage: ./fillit yourfile");
		exit(0);
	}
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
