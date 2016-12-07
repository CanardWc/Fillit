/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_lstpast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 04:59:45 by fgrea             #+#    #+#             */
/*   Updated: 2016/12/07 05:52:01 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillit_lstpast(t_list *ntl)
{
	t_list	*tmp;

	tmp = ntl;
	while (ntl->next != NULL)
	{
		ntl = ntl->next;
		ntl->previous = tmp;
		tmp = ntl;
	}
}
