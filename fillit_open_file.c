/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:47:20 by fgrea             #+#    #+#             */
/*   Updated: 2016/12/06 21:00:26 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fillit_open_file(int argc, char **argv)
{
	int fd;

	fd = open(argv[1], O_RDONLY);
	if (argc > 2)
	{
		ft_putstr("Too many arguments.\n");
		return (-1);
	}
	if (argc < 2)
	{
		ft_putstr("File name missing.\n");
		return (-1);
	}
	return (fd);
}
