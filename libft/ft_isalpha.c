/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiduarterrd <ruiduarte.rrd@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:53:36 by ruiduarterrd      #+#    #+#             */
/*   Updated: 2024/10/03 13:51:24 by ruiduarterrd     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// check if x is a letter from alphabet [a/A - z/Z]
int	ft_isalpha(int x)
{
	if (('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z'))
		return (1);
	return (0);
}
