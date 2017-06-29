/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 23:49:14 by alcornea          #+#    #+#             */
/*   Updated: 2017/01/11 16:48:26 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define CONV(x,y) convert_upperhex_to_ascii(x,y)

void	hex_long_long_length(va_list arg, int *value, char *get, t_arg mod)
{
	unsigned long long	num;
	char				*str;

	num = va_arg(arg, unsigned long long);
	g_nb = 1;
	if (mod.hex)
		str = convert_upperhex_to_ascii(num, 16);
	else
		str = convert_llu_to_ascii(num, 16);
	str = handle_int_precision(str, mod);
	if (mod.precision == 0 && num == 0 && ft_strchr(get, '.'))
		str[0] = '\0';
	if (mod.flag_hash && !mod.hex && num != 0)
		str = ft_strjoin("0x", str);
	if (mod.flag_hash && mod.hex && num != 0)
		str = ft_strjoin("0X", str);
	str = handle_int_width(str, mod);
	ft_putstr(str);
	*value += my_strlen(str);
}

void	hex_uintmax_t_length(va_list arg, int *value, char *get, t_arg mod)
{
	uintmax_t	num;
	char		*str;

	num = va_arg(arg, uintmax_t);
	g_nb = 1;
	if (mod.hex)
		str = convert_upperhex_to_ascii(num, 16);
	else
		str = convert_uintmax_t_to_ascii(num, 16);
	str = handle_int_precision(str, mod);
	if (mod.precision == 0 && num == 0 && ft_strchr(get, '.'))
		str[0] = '\0';
	if (mod.flag_hash && !mod.hex && num != 0)
		str = ft_strjoin("0x", str);
	if (mod.flag_hash && mod.hex && num != 0)
		str = ft_strjoin("0X", str);
	str = handle_int_width(str, mod);
	ft_putstr(str);
	*value += my_strlen(str);
}

void	hex_size_t_length(va_list arg, int *value, char *get, t_arg mod)
{
	size_t	num;
	char	*str;

	num = va_arg(arg, size_t);
	g_nb = 1;
	if (mod.hex)
		str = convert_upperhex_to_ascii(num, 16);
	else
		str = convert_size_t_to_ascii(num, 16);
	str = handle_int_precision(str, mod);
	if (mod.precision == 0 && num == 0 && ft_strchr(get, '.'))
		str[0] = '\0';
	if (mod.flag_hash && !mod.hex && num != 0)
		str = ft_strjoin("0x", str);
	if (mod.flag_hash && mod.hex && num != 0)
		str = ft_strjoin("0X", str);
	str = handle_int_width(str, mod);
	ft_putstr(str);
	*value += my_strlen(str);
}

void	convert_hex(va_list arg, int *value, char *get, t_arg mod)
{
	unsigned int	num;
	char			*str;
	char			*f;

	f = NULL;
	num = va_arg(arg, unsigned int);
	g_nb = 1;
	str = mod.hex ? CONV(num, 16) : convert_u_to_ascii(num, 16);
	str = handle_int_precision(str, mod);
	if (mod.precision == 0 && num == 0 && ft_strchr(get, '.'))
		str[0] = '\0';
	if (mod.flag_hash && !mod.hex && num != 0 && !mod.flag_zero)
		str = ft_strjoin("0x", str);
	if (mod.flag_hash && mod.hex && num != 0 && !mod.flag_zero)
	{
		f = ft_strjoin("0X", str);
		str = f;
	}
	if (mod.flag_hash && mod.flag_minus && mod.flag_zero)
		str = ft_strjoin("0x", str);
	str = handle_int_width(str, mod);
	ft_putstr(str);
	*value += my_strlen(str);
	if (f)
		free(f);
}

void	handle_hex(va_list arg, int *value, char *get, t_arg mod)
{
	if (mod.len_ll || mod.len_l)
		hex_long_long_length(arg, value, get, mod);
	else if (mod.len_h)
		convert_hex(arg, value, get, mod);
	else if (mod.len_hh)
		hex_unchar_len(arg, value, get, mod);
	else if (mod.len_j)
		hex_uintmax_t_length(arg, value, get, mod);
	else if (mod.len_z)
		hex_size_t_length(arg, value, get, mod);
	else
		convert_hex(arg, value, get, mod);
}
