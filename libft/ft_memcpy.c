/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiduarterrd <ruiduarte.rrd@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:55:22 by ruiduarterrd      #+#    #+#             */
/*   Updated: 2024/10/03 13:55:23 by ruiduarterrd     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// copy n bytes from src to dst
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*p;

	if (dst == NULL && src == NULL)
		return (NULL);
	p = (char *)dst;
	while (n > 0)
	{
		*p = *(char *)src;
		p++;
		src++;
		n--;
	}
	return ((void *)dst);
}
