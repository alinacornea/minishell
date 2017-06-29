/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_x_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 15:23:46 by alcornea          #+#    #+#             */
/*   Updated: 2017/01/08 15:28:16 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		len_int(int num, int base)
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

long	max_x_power(long num, int base)
{
	long pwr;

	pwr = base;
	while (pwr < num)
		pwr *= base;
	if (pwr > num)
		pwr /= base;
	return (pwr);
}

char	*ft_itoa_hex_base(int value, int base)
{
	int		i;
	long	pwr;
	long	num;
	char	*ptr;

	i = 0;
	num = (long)value;
	ptr = (char *)malloc(sizeof(char) * len_int(value, base) + 1);
	if (num < 0 && base == 10)
	{
		ptr[i] = '-';
		num = -num;
		i++;
	}
	if (num < 10 && base == 10)
		num = -num;
	pwr = max_x_power(num, base);
	while (pwr > 0)
	{
		ptr[i++] = "0123456789ABCDEF"[num / pwr];
		num %= pwr;
		pwr /= base;
	}
	ptr[i] = '\0';
	return (ptr);
}
