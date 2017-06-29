/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_big_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 23:49:14 by alcornea          #+#    #+#             */
/*   Updated: 2017/01/11 16:48:26 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_long_to_ascii(long num, int base)
{
	static char			buf[32] = "0";
	int					i;
	unsigned long long	sign;
	static char			hex[16] = "0123456789abcdef";

	i = 30;
	if (num == 0)
		return (ft_strdup("0"));
	if (num < 0)
	{
		sign = -num;
		while (sign > 0 && i > 0)
		{
			buf[i--] = hex[sign % base];
			sign /= base;
		}
		buf[i] = '-';
		return (buf + i + 1);
	}
	while (num > 0 && i > 0)
	{
		buf[i--] = hex[num % base];
		num /= base;
	}
	return (buf + i + 1);
}

void	long_length_d(va_list arg, int *value, char *get, t_arg mod)
{
	long num;
	char *str;

	num = va_arg(arg, long);
	g_nb = num;
	str = convert_long_to_ascii(num, 10);
	if (mod.precision)
	{
		str = handle_int_precision(str, mod);
		if (num < 0)
			str = ft_strjoin("-", str);
	}
	if (num < 0 && !mod.precision && !mod.width)
		str = ft_strjoin("-", str);
	if (mod.precision == 0 && num == 0 && ft_strchr(get, '.'))
		str[0] = '\0';
	if (mod.width)
		str = handle_int_width(str, mod);
	if ((mod.flag_plus || mod.flag_space) && g_nb >= 0)
		handle_all_flags(value, &str, mod);
	ft_putstr(str);
	*value += my_strlen(str);
}
