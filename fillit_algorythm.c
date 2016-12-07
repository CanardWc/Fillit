/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_algorythm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 08:39:46 by fgrea             #+#    #+#             */
/*   Updated: 2016/12/07 17:07:55 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**fillit_put_all(t_list *ntl, char **map)
{
	size_t	j;

	j = 0;
	while (ntl != NULL)
	{
		if ((map = fillit_put_tet(ntl, map)) == NULL)
		{
			ft_putendl("LOL");
			ntl->i = 0;
			ntl->j = 0;
			ntl = ntl->previous;
			ntl->swap = 1;
			return (NULL);
		}
		while (map[j])
		{
			ft_putendl(map[j]);
			j++;
		}
		ntl = ntl->next;
	}
	return (map);
}

static t_list	*fillit_increment(t_list *ntl, char **map, size_t *size)
{
	size_t	j;

	j = 0;
	while (ntl->swap != 1)
		ntl = ntl->next;
	ntl->swap = 0;
	ntl->i++;
	if ((ntl->i + ntl->wdth) > *size)
	{
		ntl->j++;
		ntl->i = 0;
		if ((ntl->j + ntl->hght - 1) > *size)
		{
			map = fillit_erase_tet(ntl, map);
			if ((ntl = ntl->previous) == NULL)
				return (NULL);
			ntl->swap = 1;
			fillit_increment(ntl, map, size);
		}
	}
	return (ntl);
}

static void		fillit_erase_increments(t_list *ntl)
{
	while (ntl != NULL)
	{
		ntl->i = 0;
		ntl->j = 0;
		ntl->swap = 0;
		ntl = ntl->next;
	}
}

char			**fillit_algorythm(t_list *ntl, size_t x)
{
	char	**map;
	size_t	size;

	size = 0;
	map = fillit_size_map(ntl, x, &size);
	while ((map = fillit_put_all(ntl, map)) == NULL)
	{
		if ((ntl = fillit_increment(ntl, map, &size)) == NULL)
		{
			fillit_erase_increments(ntl);
			if (map)
				free (map);
			fillit_algorythm(ntl, x++);
		}
	}
	return (map);
}
