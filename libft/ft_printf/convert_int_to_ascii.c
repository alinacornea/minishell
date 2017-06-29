/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int_to_ascii.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 23:49:14 by alcornea          #+#    #+#             */
/*   Updated: 2017/01/11 16:48:26 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_int_to_ascii(int num, int base)
{
	static char	buf[32] = "0";
	int			i;
	long		sign;

	i = 30;
	if (num == 0)
		return (ft_strdup("0"));
	if (num < 0)
	{
		sign = -num;
		while (sign > 0 && i > 0)
		{
			buf[i--] = "0123456789abcdef"[sign % base];
			sign /= base;
		}
		buf[i] = '-';
		return (buf + i + 1);
	}
	while (num > 0 && i > 0)
	{
		buf[i] = "0123456789abcdef"[num % base];
		num /= base;
		i--;
	}
	return (buf + i + 1);
}

char	*convert_long_long_to_ascii(long long num, int base)
{
	int					i;
	unsigned long long	sign;
	static char			buf[32] = "0";

	i = 30;
	if (num == 0)
		return (ft_strdup("0"));
	if (num < 0)
	{
		sign = -num;
		while (sign > 0 && i > 0)
		{
			buf[i--] = "0123456789abcdef"[sign % base];
			sign /= base;
		}
		buf[i] = '-';
		return (buf + i + 1);
	}
	while (num > 0 & i > 0)
	{
		buf[i] = "0123456789abcdef"[num % base];
		num /= base;
		i--;
	}
	return (buf + i + 1);
}

char	*convert_short_to_ascii(short num, int base)
{
	int			i;
	int			sign;
	static char	buf[32] = "0";

	i = 30;
	if (num == 0)
		return (ft_strdup("0"));
	if (num < 0)
	{
		sign = -num;
		while (sign > 0 && i > 0)
		{
			buf[i--] = "0123456789abcdef"[sign % base];
			sign /= base;
		}
		buf[i] = '-';
		return (buf + i + 1);
	}
	while (num > 0 & i != 0)
	{
		buf[i] = "0123456789abcdef"[num % base];
		num /= base;
		i--;
	}
	return (buf + i + 1);
}

char	*convert_ushort_to_ascii(unsigned short num, int base)
{
	int			i;
	static char	buf[32] = "0";
	static char	hex[16] = "0123456789abcdef";

	i = 30;
	if (num == 0)
		return (ft_strdup("0"));
	while (num > 0 && i > 0)
	{
		buf[i] = hex[num % base];
		num /= base;
		--i;
	}
	return (buf + i + 1);
}
