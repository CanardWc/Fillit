/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_size_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 04:58:55 by fgrea             #+#    #+#             */
/*   Updated: 2016/12/07 15:33:24 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	fillit_count_tets(t_list *ntl)
{
	size_t	ret;
	size_t	i;

	i = 0;
	ret = 0;
	while (ntl != NULL)
	{
		i++;
		ntl = ntl->next;
	}
	while ((ret * ret) < (i * 4))
		ret++;
	return (ret);
}

char	**fillit_size_map(t_list *ntl, size_t x, size_t *size)
{
	char	**map;
	size_t	i;
	size_t	j;
	size_t	ret;

	i = 0;
	j = 0;
	ret = fillit_count_tets(ntl);
	*size = ret + x;
	if ((map = (char **)malloc(sizeof(char *) * (ret + x + 1))) == NULL)
		return (NULL);
	while (j < (ret + x))
	{
		map[j] = ft_strnew(ret + x);
		ft_memset(map[j], (int)'.', (ret + x));
		j++;
	}
	map[j] = 0;
	return (map);
}
