/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiduarterrd <ruiduarte.rrd@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:51:28 by ruiduarterrd      #+#    #+#             */
/*   Updated: 2024/10/03 13:51:02 by ruiduarterrd     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// alloc memony for a array[x], and initialize all byte with value 0
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = malloc(nmemb * size);
	if (p == NULL)
		return NULL;
	ft_bzero(p, nmemb * size);
	return (p);
}
