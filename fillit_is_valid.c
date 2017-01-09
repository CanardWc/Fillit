/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_is_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:56:10 by nterol            #+#    #+#             */
/*   Updated: 2016/12/06 20:51:53 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	fillit_is_square(char *tmp)
{
	int i;

	i = 0;
	while (i < 20 && tmp[i])
		i++;
	if (!tmp[i + 5] && tmp[i] == '\n')
		return (1);
	if (i != 20 || (tmp[i] != '\n' && tmp[i] != '\0'))
		return (1);
	i -= 1;
	while (i >= 4)
	{
		if (tmp[i] != '\n' && tmp[i] != '\0')
			return (1);
		i = i - 5;
	}
	return (0);
}

static int	fillit_is_normed(char *tmp)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (fillit_is_square(tmp) == 0)
	{
		while (j <= 20 && tmp[j] != '\0' && (tmp[j] == '.' || \
				tmp[j] == '#' || tmp[j] == '\n'))
		{
			if (tmp[j] == '#')
				i++;
			j++;
		}
		if (i == 4)
			return (0);
	}
	return (1);
}

static int	fillit_is_after(char *tmp)
{
	int i;
	int tetri;

	i = 0;
	tetri = 0;
	while (tmp[i] && i <= 19)
	{
		if (tmp[i] == '#')
		{
			if (tmp[i + 1] == '#')
				tetri++;
			if (tmp[i + 5] == '#' && (i + 5) <= 19)
				tetri++;
		}
		i++;
	}
	return (tetri);
}

static int	fillit_is_before(char *tmp)
{
	int j;
	int tetro;

	j = 0;
	tetro = 0;
	while (tmp[j] && j <= 19)
	{
		if (tmp[j] == '#')
		{
			if (tmp[j - 1] == '#')
				tetro++;
			if (tmp[j - 5] == '#' && (j - 5) >= 0)
				tetro++;
		}
		j++;
	}
	return (tetro);
}

int			fillit_is_valid(char *tmp)
{
	int tetra;

	if (fillit_is_normed(tmp) == 0)
	{
		tetra = fillit_is_after(tmp) + fillit_is_before(tmp);
		if (tetra == 6 || tetra == 8)
			return (0);
	}
	ft_putendl("error");
	exit (1);
}
