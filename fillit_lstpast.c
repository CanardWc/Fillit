/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_lstpast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 04:59:45 by fgrea             #+#    #+#             */
/*   Updated: 2016/12/09 06:46:33 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillit_lstpast(t_list *ntl)
{
	t_list	*tmp;

	tmp = ntl;
	while (ntl->next != NULL)
	{
		ntl->previous = tmp;
		ntl = ntl->next;
		tmp = ntl;
	}
}
