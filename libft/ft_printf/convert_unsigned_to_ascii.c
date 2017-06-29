/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_unsigned_to_ascii.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 23:49:14 by alcornea          #+#    #+#             */
/*   Updated: 2017/01/11 16:48:26 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_u_to_ascii(unsigned int num, int base)
{
	int			i;
	static char buf[32] = "0";
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

char	*convert_size_t_to_ascii(size_t num, int base)
{
	int			i;
	static char buf[32] = "0";
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

char	*convert_llu_to_ascii(unsigned long long num, int base)
{
	int			i;
	static char buf[32] = "0";
	static char hex[16] = "0123456789abcdef";

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

char	*convert_uintmax_t_to_ascii(uintmax_t num, int base)
{
	int			i;
	static char buf[32] = "0";
	static char hex[16] = "0123456789abcdef";

	i = 30;
	if (num == 0)
		return (ft_strdup("0"));
	while (num > 0 && i > 0)
	{
		buf[i] = hex[num % base];
		num /= base;
		i--;
	}
	return (buf + i + 1);
}

char	*convert_upperhex_to_ascii(uintmax_t num, int base)
{
	int			i;
	static char buf[32] = "0";
	static char hex[16] = "0123456789ABCDEF";

	i = 30;
	if (num == 0)
		return (ft_strdup("0"));
	while (num > 0 && i > 0)
	{
		buf[i] = hex[num % base];
		num /= base;
		i--;
	}
	return (buf + i + 1);
}
