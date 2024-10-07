/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiduarterrd <ruiduarte.rrd@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:59:33 by ruiduarterrd      #+#    #+#             */
/*   Updated: 2024/10/03 13:51:52 by ruiduarterrd     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// chark if x is printable [32 - 126]
int	ft_isprint(int x)
{
	if (32 <= x && x <= 126)
		return (1);
	return (0);
}
