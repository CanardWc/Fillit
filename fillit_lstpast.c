/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_lstpast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 04:59:45 by fgrea             #+#    #+#             */
/*   Updated: 2017/01/21 02:25:06 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tet	*fillit_lstpast(t_tet *ntl)
{
	t_tet	*tmp;
	t_tet	*tmp2;

	tmp = NULL;
	tmp2 = ntl;
	while (tmp2)
	{
		tmp2->previous = tmp;
		tmp = tmp2;
		tmp2 = tmp2->next;
	}
	return (ntl);
}
