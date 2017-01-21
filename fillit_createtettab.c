/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_createtettab.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:17:18 by fgrea             #+#    #+#             */
/*   Updated: 2017/01/21 03:44:11 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**fctt_next(char *tmp, char c, int i, int j)
{
	int		itab;
	char	**tab;

	itab = 0;
	if ((tab = (char **)malloc(sizeof(char *) * (5))) == NULL)
		return (NULL);
	tab[j] = ft_strnew(5);
	while (tmp[i] && i < 20)
	{
		if (tmp[i] == '#')
			tab[j][itab] = c;
		else if (tmp[i] == '.')
			tab[j][itab] = '.';
		itab++;
		i++;
		if ((itab % 5) == 0)
		{
			itab = 0;
			j++;
			tab[j] = (i == 20) ? 0 : ft_strnew(5);
		}
	}
	return (tab);
}

char			**fillit_createtettab(char *tmp, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!tmp[i])
		return (NULL);
	return (fctt_next(tmp, c, i, j));
}
