/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_lstpast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 04:59:45 by fgrea             #+#    #+#             */
/*   Updated: 2016/12/10 21:30:20 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*fillit_lstpast(t_list *ntl)
{
	t_list	*tmp;
	t_list	*tmp2;

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
