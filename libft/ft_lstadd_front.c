/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiduarterrd <ruiduarte.rrd@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:05:01 by ruiduarterrd      #+#    #+#             */
/*   Updated: 2024/10/03 12:06:06 by ruiduarterrd     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// add a new element, new, to the beginning of the list, lst
void	ft_lstadd_front(t_list **lst, t_list *new_node)
{
	if (new_node == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new_node;
		new_node->next = NULL;
		return ;
	}
	new_node->next = *lst;
	*lst = new_node;
}
