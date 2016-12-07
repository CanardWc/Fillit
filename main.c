/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:42:16 by fgrea             #+#    #+#             */
/*   Updated: 2016/12/07 17:02:25 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	t_list	*ntl;
	char	**map;
	size_t	j;

	j = 0;
	argc = 2;								//a virer pour mettre la merde style cp
	fd = open(argv[1], O_RDONLY);
	ntl = fillit_read_file(fd);
	fillit_lstpast(ntl);
	map = fillit_algorythm(ntl, 0);
	while (map[j])
	{
		ft_putendl(map[j]);
		j++;
	}
	return (0);
}
