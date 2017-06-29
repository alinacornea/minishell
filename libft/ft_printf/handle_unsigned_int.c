/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 23:49:14 by alcornea          #+#    #+#             */
/*   Updated: 2017/01/11 16:48:26 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	unsigned_long_long_length(va_list arg, int *value, char *get, t_arg mod)
{
	unsigned long long	num;
	char				*str;

	num = va_arg(arg, unsigned long long);
	g_nb = 1;
	str = convert_llu_to_ascii(num, 10);
	str = handle_int_precision(str, mod);
	if (mod.precision == 0 && num == 0 && ft_strchr(get, '.'))
		str[0] = '\0';
	str = handle_int_width(str, mod);
	ft_putstr(str);
	*value += my_strlen(str);
}

void	unsigned_size_t_length(va_list arg, int *value, char *get, t_arg mod)
{
	size_t	num;
	char	*str;

	num = va_arg(arg, size_t);
	g_nb = 1;
	str = convert_size_t_to_ascii(num, 10);
	str = handle_int_precision(str, mod);
	if (mod.precision == 0 && num == 0 && ft_strchr(get, '.'))
		str[0] = '\0';
	str = handle_int_width(str, mod);
	ft_putstr(str);
	*value += my_strlen(str);
}

void	uintmax_t_length(va_list arg, int *value, char *get, t_arg mod)
{
	uintmax_t	num;
	char		*str;

	num = va_arg(arg, uintmax_t);
	g_nb = 1;
	str = convert_uintmax_t_to_ascii(num, 10);
	str = handle_int_precision(str, mod);
	if (mod.precision == 0 && num == 0 && ft_strchr(get, '.'))
		str[0] = '\0';
	str = handle_int_width(str, mod);
	ft_putstr(str);
	*value += my_strlen(str);
}

void	convert_unsigned_int(va_list arg, int *value, char *get, t_arg mod)
{
	unsigned int	num;
	char			*str;

	num = va_arg(arg, unsigned int);
	g_nb = 1;
	str = convert_u_to_ascii(num, 10);
	str = handle_int_precision(str, mod);
	if (mod.precision == 0 && num == 0 && ft_strchr(get, '.'))
		str[0] = '\0';
	str = handle_int_width(str, mod);
	ft_putstr(str);
	*value += my_strlen(str);
}

void	handle_uns_int(va_list arg, int *value, char *get, t_arg mod)
{
	if (mod.len_ll)
		unsigned_long_long_length(arg, value, get, mod);
	else if (mod.len_l)
		unsigned_l_len(arg, value, get, mod);
	else if (mod.len_hh)
		unsign_char_len(arg, value, get, mod);
	else if (mod.len_j)
		uintmax_t_length(arg, value, get, mod);
	else if (mod.len_z)
		unsigned_size_t_length(arg, value, get, mod);
	else
		convert_unsigned_int(arg, value, get, mod);
}
