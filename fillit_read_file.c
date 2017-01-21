/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_read_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:44:15 by fgrea             #+#    #+#             */
/*   Updated: 2017/01/21 02:27:38 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tet		*fillit_read_file(int fd)
{
	int		ret;
	char	*tmp;
	char	c;
	t_tet	*ntl;

	tmp = ft_strnew(600);
	ret = read(fd, tmp, 600);
	c = 'A';
	ntl = fillit_newtetslist(tmp, c);
	return (ntl);
}
