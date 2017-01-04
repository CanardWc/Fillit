/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_newtetlist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:57:30 by fgrea             #+#    #+#             */
/*   Updated: 2016/12/09 04:25:40 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_list	*fillit_lstnew(char **tab, char *tmp)
{
	t_list	*ntl;

	if (!tmp)
		return (NULL);
	fillit_is_valid(tmp);
	if ((ntl = (t_list *)malloc(sizeof(t_list))) == NULL)
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

t_list			*fillit_newtetslist(char *tmp, char c)
{
	t_list	*ntl;
	t_list	*save;
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
	while (*tmp)
	{
		tmp++;
		i++;
		g++;
		c++;
		if (*tmp)
		{
			ntl->next = fillit_lstnew(fillit_createtettab(tmp, c), tmp);
			ntl->next = fillit_reduce_tet(ntl->next);
			ntl = ntl->next;
			g = g + 20;
		}
		if (*tmp)
		{
			while (i < g)
			{
				tmp++;
				i++;
			}
		}
	}
	return (save);
}
