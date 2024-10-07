/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiduarterrd <ruiduarte.rrd@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:53:04 by ruiduarterrd      #+#    #+#             */
/*   Updated: 2024/10/03 13:51:12 by ruiduarterrd     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// chack if x is a caracter from the alphabet [a/A - z/Z]  or a digit [0 - 9]
int	ft_isalnum(int x)
{
	if (ft_isdigit(x) == 1 || ft_isalpha(x) == 1)
		return (1);
	return (0);
}
