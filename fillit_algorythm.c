/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_algorythm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 08:39:46 by fgrea             #+#    #+#             */
/*   Updated: 2016/12/09 06:44:19 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static size_t		fillit_put_all(t_list *ntl, char **map)
{
	size_t	j;

	j = 0;
		while (ntl)
	{
		if (fillit_put_tet(ntl, map) == 1)
		{
			ntl->i = 0;
			ntl->j = 0;
			ntl = ntl->previous;
			ntl->swap = 1;
			return (1);
		}
		ft_putchar('\n');
		while (map[j])
		{
			ft_putendl(map[j]);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		ntl = ntl->next;
	}
	return (0);
}

static size_t	fillit_increment(t_list *ntl, char **map)
{
	size_t	j;

	j = 0;
	while (ntl->swap != 1)
		ntl = ntl->next;
	ntl->swap = 0;
	ntl->i++;
	/*while (map[j])
	{
		ft_putendl(map[j]);
		j++;
	}
	j = 0;*/
	ft_putnbrendl(ntl->i + (ntl->previous)->i);
	ft_putnbrendl(ntl->j);
	//ft_putnbrendl(ntl->j + ntl->wdth);
	if (!map[ntl->j][ntl->i + ntl->wdth - 1])
	{
		ntl->j++;
		ntl->i = 0;
		if (!map[ntl->j + ntl->hght - 1])
		{

			/*ft_putendl("SOUSRACE");
			while (ntl->tab[j])
			{
				ft_putendl(ntl->tab[j]);
				j++;
			}
			j = 0;*/
			//map = fillit_erase_tet(ntl, map);
			ntl->i = 0;
			ntl->j = 0;
			if ((ntl = ntl->previous) == NULL)
			{
				ft_putendl("FAIL");
				return (1);
			}
			ntl->swap = 1;
			fillit_increment(ntl, map);
			if (!ntl->next)
				return (0);
		}
	}
	return (0);
}

static t_list		*fillit_erase_increments(t_list *ntl)
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

char			**fillit_algorythm(t_list *ntl, size_t x)
{
	char	**map;

	map = fillit_size_map(ntl, x);
	ft_putnbrendl(x);
	while (fillit_put_all(ntl, map) == 1)
	{
		if (fillit_increment(ntl, map) == 1)
		{
			if (map)
				free(map);
			ft_putnbrendl(x);
			ntl = fillit_erase_increments(ntl);
			fillit_algorythm(ntl, x + 1);
		}
	}
	return (map);
}
