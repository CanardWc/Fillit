/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_put_tet.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:49:38 by fgrea             #+#    #+#             */
/*   Updated: 2016/12/07 17:14:18 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**fillit_erase_tet(t_list *ntl, char **map)
{
	size_t	i;
	size_t	j;
	char	c;
	
	i = 0;
	j = 0;
	while (ntl->tab[j][i] == '.')
		i++;
	c = ntl->tab[j][i];
	i = 0;
	while (map[j])
	{
		if (map[j][i] == c)
			map[j][i] = '.';
		i++;
		if (map[j][i] == '\0')
		{
			j++;
			i = 0;
		}
	}
	return (map);
}

char		**fillit_put_tet(t_list *ntl, char **map)
{
	size_t	i;
	size_t	j;

	i = ntl->i;
	j = ntl->j;
	ntl->i = 0;
	ntl->j = 0;
	//map = fillit_erase_tet(ntl, map);
	while (map[j])
	{
		while (map[j] && \
				(map[j][i] == '.' || \
				 ntl->tab[ntl->j][ntl->i] == '.'))
		{
			if (ntl->tab[ntl->j][ntl->i] != '.' && \
					ntl->tab[ntl->j][ntl->i] != '\0')
				map[j][i] = ntl->tab[ntl->j][ntl->i];
			i++;
			ntl->i++;
			if (ntl->tab[ntl->j][ntl->i] == '\0')
			{
				ntl->j++;
				j++;
				//ft_putendl(map[j]);
				i = i - ntl->i;
				ntl->i = 0;
			}
			if (ntl->j == ntl->hght)
			{
				ntl->j = j - ntl->j;
				ntl->i = i - ntl->i;
				return (map);
			}
		}
		map = fillit_erase_tet(ntl, map);
		i = i - ntl->i + 1;
		ntl->i= 0;
		j = j - ntl->j;
		ntl->j = 0;
		if (map[j][i] == '\0')
		{
			i = 0;
			j++;
		}
	}
	return (NULL);
}
