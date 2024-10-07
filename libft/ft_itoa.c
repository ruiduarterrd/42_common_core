/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiduarterrd <ruiduarte.rrd@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:02:48 by ruiduarterrd      #+#    #+#             */
/*   Updated: 2024/10/03 13:52:20 by ruiduarterrd     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int num);

// convert int to string of chars
char	*ft_itoa(int n)
{
	int			len;
	int long	num;
	char		*str;

	num = n;
	len = ft_numlen(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len--] = '\0';
	if (num == 0)
		*str = '0';
	else if (num < 0)
	{
		num = num * -1;
		*str = '-';
	}
	while (num > 0)
	{
		str[len--] = ('0' + (num % 10));
		num = num / 10;
	}
	return (str);
}

// gives length of the number
static int	ft_numlen(int num)
{
	int	len;

	if (num > 0)
		len = 0;
	else
		len = 1;
	while (num)
	{
		num = num / 10;
		len++;
	}
	return len;
}
