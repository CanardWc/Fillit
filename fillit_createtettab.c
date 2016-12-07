/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_createtettab.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:17:18 by fgrea             #+#    #+#             */
/*   Updated: 2016/12/06 20:53:55 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**fillit_createtettab(char *tmp, char c)
{
	int 	i;
	int		j;
	int 	itab;
	char	**tab;

	i = 0;
	j = 0;
	itab = 0;
	if (!tmp[i])
		return (NULL);
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
			if (i == 20)
				tab[j] = 0;
			else
				tab[j] = ft_strnew(5);
		}
	}
	return (tab);
}
