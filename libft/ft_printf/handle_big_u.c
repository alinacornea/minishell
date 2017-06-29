/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_big_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 23:49:14 by alcornea          #+#    #+#             */
/*   Updated: 2017/01/11 16:48:26 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_lu_to_ascii(unsigned long num, int base)
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

void	octal_long_len(va_list arg, int *value, char *get, t_arg mod)
{
	unsigned long	num;
	char			*str;

	num = va_arg(arg, unsigned long);
	g_nb = 1;
	str = convert_llu_to_ascii(num, 8);
	str = handle_int_precision(str, mod);
	if (mod.precision == 0 && num == 0 && ft_strchr(get, '.'))
	{
		str[0] = '\0';
		if (mod.flag_hash)
			str = ft_strdup("0");
	}
	if (mod.flag_hash && num != 0 && !mod.precision)
		str = ft_strjoin("0", str);
	str = handle_int_width(str, mod);
	ft_putstr(str);
	*value += my_strlen(str);
}

void	unsigned_l_len(va_list arg, int *value, char *get, t_arg mod)
{
	unsigned long	num;
	char			*str;

	num = va_arg(arg, unsigned long);
	g_nb = 1;
	str = convert_lu_to_ascii(num, 10);
	str = handle_int_precision(str, mod);
	if (mod.precision == 0 && num == 0 && ft_strchr(get, '.'))
		str[0] = '\0';
	str = handle_int_width(str, mod);
	ft_putstr(str);
	*value += my_strlen(str);
}
