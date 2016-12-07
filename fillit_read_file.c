/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_read_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:44:15 by fgrea             #+#    #+#             */
/*   Updated: 2016/12/06 21:00:51 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list		*fillit_read_file(int fd)
{
	int		ret;
	char	*tmp;
	char	c;
	t_list	*ntl;

	tmp = ft_strnew(600);
	ret = read(fd, tmp, 600);
	c = 'A';
	ntl = fillit_newtetslist(tmp, c);
	return (ntl);
}
