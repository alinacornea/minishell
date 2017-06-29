/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 23:49:14 by alcornea          #+#    #+#             */
/*   Updated: 2017/01/11 16:48:26 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	octal_short_length(va_list arg, int *value, char *get, t_arg mod)
{
	unsigned int	num;
	char			*str;

	num = va_arg(arg, unsigned int);
	g_nb = 1;
	str = convert_ushort_to_ascii(num, 8);
	if (mod.precision)
		str = handle_int_precision(str, mod);
	if (mod.precision == 0 && num == 0 && ft_strchr(get, '.'))
	{
		str[0] = '\0';
		if (mod.flag_hash)
			str = ft_strdup("0");
	}
	if (mod.flag_hash && num != 0 && !mod.precision)
		str = ft_strjoin("0", str);
	if (mod.width)
		str = handle_int_width(str, mod);
	ft_putstr(str);
	*value += my_strlen(str);
}

void	octal_uintmax_t_length(va_list arg, int *value, char *get, t_arg mod)
{
	uintmax_t	num;
	char		*str;

	num = va_arg(arg, uintmax_t);
	g_nb = 1;
	str = convert_uintmax_t_to_ascii(num, 8);
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

void	octal_size_t_length(va_list arg, int *value, char *get, t_arg mod)
{
	size_t	num;
	char	*str;

	num = va_arg(arg, size_t);
	g_nb = 1;
	str = convert_size_t_to_ascii(num, 8);
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

void	convert_octal(va_list arg, int *value, char *get, t_arg mod)
{
	unsigned int	num;
	char			*str;

	num = va_arg(arg, unsigned int);
	g_nb = 1;
	str = convert_u_to_ascii(num, 8);
	if (mod.precision)
		str = handle_int_precision(str, mod);
	if (mod.precision == 0 && num == 0 && ft_strchr(get, '.'))
	{
		str[0] = '\0';
		if (mod.flag_hash)
			str = ft_strdup("0");
	}
	if (mod.flag_hash && num != 0 && !mod.precision)
		str = ft_strjoin("0", str);
	if (mod.width)
		str = handle_int_width(str, mod);
	ft_putstr(str);
	*value += my_strlen(str);
}

void	handle_octal(va_list arg, int *value, char *get, t_arg mod)
{
	if (mod.len_ll || mod.len_l)
		octal_uintmax_t_length(arg, value, get, mod);
	else if (mod.len_h)
		octal_short_length(arg, value, get, mod);
	else if (mod.len_hh)
		octal_unchar_len(arg, value, get, mod);
	else if (mod.len_j)
		octal_uintmax_t_length(arg, value, get, mod);
	else if (mod.len_z)
		octal_size_t_length(arg, value, get, mod);
	else
		convert_octal(arg, value, get, mod);
}
