/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 12:25:42 by alcornea          #+#    #+#             */
/*   Updated: 2017/04/20 12:25:48 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		len(int num, int base)
{
	int i;

	i = 0;
	if (num < 0 && base == 10)
	{
		num = -num;
		i++;
	}
	if (num < 0 && base != 10)
		num = -num;
	while (num > 0)
	{
		num /= base;
		i++;
	}
	return (i);
}

long	max_power(long num, int base)
{
	long pwr;

	pwr = base;
	while (pwr < num)
		pwr *= base;
	if (pwr > num)
		pwr /= base;
	return (pwr);
}

char	*ft_itoa_base(int value, int base)
{
	int		i;
	long	pwr;
	long	num;
	char	*ptr;

	i = 0;
	num = (long)value;
	ptr = (char *)malloc(sizeof(char) * len(value, base) + 1);
	if (num < 0 && base == 10)
	{
		ptr[i] = '-';
		num = -num;
		i++;
	}
	if (num < 10 && base == 10)
		num = -num;
	pwr = max_power(num, base);
	while (pwr > 0)
	{
		ptr[i++] = "0123456789abcdef"[num / pwr];
		num %= pwr;
		pwr /= base;
	}
	ptr[i] = '\0';
	return (ptr);
}
