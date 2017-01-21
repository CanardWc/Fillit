/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_put_tet.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:49:38 by fgrea             #+#    #+#             */
/*   Updated: 2017/01/21 04:34:46 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			**fillit_erase_tet(t_tet *ntl, char **map)
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

static size_t	fpt_next(t_tet *ntl, t_map *p)
{
	while (p->map[p->j] && \
			(p->map[p->j][p->i] == '.' || \
				ntl->tab[ntl->j][ntl->i] == '.'))
	{
		if (ntl->tab[ntl->j][ntl->i] != '.' && \
				ntl->tab[ntl->j][ntl->i] != '\0')
			p->map[p->j][p->i] = ntl->tab[ntl->j][ntl->i];
		p->i++;
		ntl->i++;
		if (ntl->tab[ntl->j][ntl->i] == '\0')
		{
			ntl->j++;
			p->j++;
			p->i = p->i - ntl->i;
			ntl->i = 0;
		}
		if (ntl->j == ntl->hght)
		{
			ntl->j = p->j - ntl->j;
			ntl->i = p->i - ntl->i;
			return (0);
		}
	}
	return (1);
}

size_t			fillit_put_tet(t_tet *ntl, t_map *p)
{
	p->i = ntl->i;
	p->j = ntl->j;
	ntl->i = 0;
	ntl->j = 0;
	p->map = fillit_erase_tet(ntl, p->map);
	while (p->map[p->j])
	{
		if (fpt_next(ntl, p) == 0)
			return (0);
		p->map = fillit_erase_tet(ntl, p->map);
		p->i = p->i - ntl->i + 1;
		ntl->i = 0;
		p->j = p->j - ntl->j;
		ntl->j = 0;
		if (p->map[p->j][p->i] == '\0')
		{
			p->i = 0;
			p->j++;
		}
	}
	return (1);
}
