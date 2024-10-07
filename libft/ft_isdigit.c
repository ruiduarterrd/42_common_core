/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiduarterrd <ruiduarte.rrd@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:56:38 by ruiduarterrd      #+#    #+#             */
/*   Updated: 2024/10/03 13:51:42 by ruiduarterrd     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// check if x is a digit [0 - 9]
int	ft_isdigit(int x)
{
	if ('0' <= x && x <= '9')
		return (1);
	return (0);
}
