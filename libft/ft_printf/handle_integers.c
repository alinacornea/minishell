/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_integers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 23:49:14 by alcornea          #+#    #+#             */
/*   Updated: 2017/01/11 16:48:26 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	long_long_length_d(va_list arg, int *value, char *get, t_arg mod)
{
	long long	num;
	char		*str;

	num = va_arg(arg, long long);
	g_nb = num;
	str = convert_long_long_to_ascii(num, 10);
	if (mod.precision)
	{
		str = handle_int_precision(str, mod);
		if (num < 0)
			str = ft_strcat("-", str);
	}
	if (num < 0 && !mod.precision && !mod.width)
		str = ft_strcat("-", str);
	if (mod.precision == 0 && num == 0 && ft_strchr(get, '.'))
		str[0] = '\0';
	if (mod.width)
		str = handle_int_width(str, mod);
	if ((mod.flag_plus || mod.flag_space) && g_nb >= 0)
		handle_all_flags(value, &str, mod);
	ft_putstr(str);
	*value += my_strlen(str);
}

void	ssize_t_length_d(va_list arg, int *value, char *get, t_arg mod)
{
	ssize_t	num;
	char	*str;

	num = va_arg(arg, ssize_t);
	g_nb = 1;
	str = convert_long_long_to_ascii(num, 10);
	if (mod.precision)
	{
		str = handle_int_precision(str, mod);
		if (num < 0)
			str = ft_strcat("-", str);
	}
	if (num < 0 && !mod.precision && !mod.width)
		str = ft_strcat("-", str);
	if (mod.precision == 0 && num == 0 && ft_strchr(get, '.'))
		str[0] = '\0';
	if (mod.width)
		str = handle_int_width(str, mod);
	if ((mod.flag_plus || mod.flag_space) && g_nb >= 0)
		handle_all_flags(value, &str, mod);
	ft_putstr(str);
	*value += my_strlen(str);
}

void	short_length_d(va_list arg, int *value, char *get, t_arg mod)
{
	short	num;
	char	*str;

	num = va_arg(arg, int);
	g_nb = num;
	str = convert_short_to_ascii(num, 10);
	if (mod.precision)
	{
		str = handle_int_precision(str, mod);
		if (num < 0)
			str = ft_strcat("-", str);
	}
	if (num < 0 && !mod.precision && !mod.width)
		str = ft_strcat("-", str);
	if (mod.precision == 0 && num == 0 && ft_strchr(get, '.'))
		str[0] = '\0';
	if (mod.width)
		str = handle_int_width(str, mod);
	if ((mod.flag_plus || mod.flag_space) && g_nb >= 0)
		handle_all_flags(value, &str, mod);
	ft_putstr(str);
	*value += my_strlen(str);
}

void	intmax_t_length_d(va_list arg, int *value, char *get, t_arg mod)
{
	intmax_t	num;
	char		*str;

	num = va_arg(arg, intmax_t);
	g_nb = num;
	str = convert_long_long_to_ascii(num, 10);
	if (mod.precision)
	{
		str = handle_int_precision(str, mod);
		if (num < 0)
			str = ft_strcat("-", str);
	}
	if (num < 0 && !mod.precision && !mod.width)
		str = ft_strcat("-", str);
	if (mod.precision == 0 && num == 0 && ft_strchr(get, '.'))
		str[0] = '\0';
	if (mod.width)
		str = handle_int_width(str, mod);
	if ((mod.flag_plus || mod.flag_space) && g_nb >= 0)
		handle_all_flags(value, &str, mod);
	ft_putstr(str);
	*value += my_strlen(str);
}

void	handle_integers(va_list arg, int *value, char *get, t_arg mod)
{
	if (mod.len_ll || mod.len_l)
		long_long_length_d(arg, value, get, mod);
	else if (mod.len_h)
		short_length_d(arg, value, get, mod);
	else if (mod.len_hh)
		handle_sign_char(arg, value, get, mod);
	else if (mod.len_j)
		intmax_t_length_d(arg, value, get, mod);
	else if (mod.len_z)
		ssize_t_length_d(arg, value, get, mod);
	else
		convert_integers(arg, value, get, mod);
}
