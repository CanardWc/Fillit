/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_reduce_tet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 08:27:00 by fgrea             #+#    #+#             */
/*   Updated: 2016/12/10 21:06:54 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		fcw(t_list *ntl)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (ntl->tab[j][i] != '.' && ntl->tab[j][i] != '\0')
		{
			ntl->wdth++;
			i++;
			j = 0;
		}
		j++;
		if (j == 4)
		{
			j = 0;
			i++;
		}
	}
}

static void		fch(t_list *ntl)
{
	size_t	i;
	size_t	j;
	size_t	cnt;

	i = 0;
	j = 0;
	cnt = 0;
	while (ntl->tab[j])
	{
		if (ntl->tab[j][i] != '.' && ntl->tab[j][i] != '\0')
			cnt++;
		i++;
		if (ntl->tab[j] && ntl->tab[j][i] == '\0')
		{
			if (cnt != 0)
			{
				cnt = 0;
				ntl->hght++;
			}
			i = 0;
			j++;
		}
	}
}

static size_t	fblt(t_list *ntl)
{
	size_t	i;
	size_t	j;
	size_t	begin_line;
	size_t	cnt;

	i = 0;
	j = 0;
	begin_line = 0;
	cnt = 0;
	while (ntl->tab[j])
	{
		if (ntl->tab[j][i] != '.' && ntl->tab[j][i] != '\0')
			cnt++;
		i++;
		if (ntl->tab[j][i] == '\0')
		{
			if (cnt != 0)
				return (begin_line);
			begin_line++;
			i = 0;
			j++;
		}
	}
	return (begin_line);
}

static size_t	fbct(t_list *ntl)
{
	size_t	newbeg;
	size_t	beg;
	size_t	i;
	size_t	j;

	newbeg = 5;
	beg = 5;
	i = 0;
	j = 0;
	while (ntl->tab[j])
	{
		if (ntl->tab[j][i] != '.' && ntl->tab[j][i] != '\0')
		{
			newbeg = i;
			if (newbeg < beg)
				beg = newbeg;
		}
		i++;
		if (ntl->tab[j][i] == '\0')
		{
			i = 0;
			j++;
		}
	}
	return (beg);
}

t_list			*fillit_reduce_tet(t_list *ntl)
{
	size_t	i;
	size_t	j;
	char	**tet;

	i = fbct(ntl);
	j = fblt(ntl);
	fch(ntl);
	fcw(ntl);
	if ((tet = (char **)malloc(sizeof(char *) * (ntl->hght + 1))) == NULL)
		return (NULL);
	while (ntl->tab[j] && j < (ntl->hght + fblt(ntl)))
	{
		tet[j - fblt(ntl)] = ft_strnew(ntl->wdth);
		while ((i - fbct(ntl)) < ntl->wdth)
		{
			tet[j - fblt(ntl)][i - fbct(ntl)] = ntl->tab[j][i];
			i++;
		}
		i = fbct(ntl);
		j++;
	}
	tet[j - fblt(ntl)] = 0;
	ntl->tab = tet;
	return (ntl);
}
