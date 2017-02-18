/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_newtetlist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:57:30 by fgrea             #+#    #+#             */
/*   Updated: 2017/02/18 04:39:02 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		fillit_checkc(char c)
{
	if (c > 'Z')
	{
		ft_putendl("error");
		exit(0);
	}
}

static t_tet	*fillit_lstnew(char **tab, char *tmp)
{
	t_tet	*ntl;

	if (!tmp)
		return (NULL);
	fillit_is_valid(tmp);
	if ((ntl = (t_tet *)malloc(sizeof(t_tet))) == NULL)
		return (NULL);
	ntl->tab = tab;
	ntl->i = 0;
	ntl->j = 0;
	ntl->wdth = 0;
	ntl->hght = 0;
	ntl->swap = 0;
	ntl->next = NULL;
	ntl->previous = NULL;
	return (ntl);
}

static t_tet	*fntl(t_tet *ntl, char *tmp, char c, int i)
{
	int	g;

	g = i;
	while (*tmp)
	{
		tmp++;
		i++;
		g++;
		c++;
		fillit_checkc(c);
		if (*tmp)
		{
			ntl->next = fillit_lstnew(fillit_createtettab(tmp, c), tmp);
			ntl->next = fillit_reduce_tet(ntl->next);
			ntl = ntl->next;
			g = g + 20;
		}
		while (i < g)
		{
			tmp++;
			i++;
		}
	}
	return (ntl);
}

t_tet			*fillit_newtetslist(char *tmp, char c)
{
	t_tet	*ntl;
	t_tet	*save;
	int		i;
	int		g;

	i = 0;
	g = 20;
	ntl = fillit_lstnew(fillit_createtettab(tmp, c), tmp);
	ntl = fillit_reduce_tet(ntl);
	save = ntl;
	while (i < g)
	{
		tmp++;
		i++;
	}
	ntl = fntl(ntl, tmp, c, i);
	return (save);
}
