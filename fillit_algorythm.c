/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_algorythm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 08:39:46 by fgrea             #+#    #+#             */
/*   Updated: 2017/01/21 04:31:44 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static size_t	fillit_put_all(t_tet *ntl, t_map *p)
{
	while (ntl)
	{
		if (ntl->swap == 1)
		{
			if (fillit_put_tet(ntl, p) == 1)
			{
				ntl->swap = 2;
				return (1);
			}
			ntl->swap = 0;
			if ((ntl = ntl->next) == NULL)
				return (0);
			ntl->swap = 1;
		}
		if (ntl->swap == 0)
			ntl = ntl->next;
		if (ntl->swap == 2)
			return (1);
	}
	return (0);
}

static size_t	fillit_increment(t_tet *ntl, char **map)
{
	while (ntl->swap != 2)
		ntl = ntl->next;
	ntl->swap = 0;
	map = fillit_erase_tet(ntl, map);
	if ((ntl = ntl->previous) == NULL)
		return (1);
	ntl->swap = 1;
	ntl->i++;
	if (!map[ntl->j][ntl->i + ntl->wdth - 1])
	{
		ntl->j++;
		ntl->i = 0;
		if (!map[ntl->j + ntl->hght - 1])
		{
			map = fillit_erase_tet(ntl, map);
			ntl->i = 0;
			ntl->j = 0;
			ntl->swap = 2;
		}
	}
	return (0);
}

static t_tet	*fillit_erase_increments(t_tet *ntl)
{
	while (ntl != NULL)
	{
		ntl->i = 0;
		ntl->j = 0;
		ntl->swap = 0;
		ntl = ntl->next;
	}
	return (ntl);
}

static char		**fillit_backtrack(t_tet *ntl, t_map *p)
{
	while (fillit_put_all(ntl, p) == 1)
	{
		if (fillit_increment(ntl, p->map) == 1)
		{
			ntl = fillit_erase_increments(ntl);
			return (NULL);
		}
	}
	return (p->map);
}

char			**fillit_algorythm(t_tet *ntl, size_t x)
{
	t_map	*p;

	if ((p = (t_map *)malloc(sizeof(t_map))) == NULL)
		return (NULL);
	p->i = 0;
	p->j = 0;
	ntl->swap = 1;
	p->map = fillit_size_map(ntl, x);
	while ((p->map = fillit_backtrack(ntl, p)) == NULL)
	{
		ntl->swap = 1;
		p->map = fillit_size_map(ntl, ++x);
	}
	return (p->map);
}
