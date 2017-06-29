/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 23:49:14 by alcornea          #+#    #+#             */
/*   Updated: 2017/01/11 16:48:26 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_float(va_list arg, int *value, char *get, t_arg mod)
{
	double	num;
	char	*str;
	char	*dot;

	num = va_arg(arg, double);
	g_nb = num;
	str = ft_ftoa(num, 6);
	if (mod.precision)
		str = ft_ftoa(num, mod.precision);
	if (num < 0 && !mod.precision && !mod.width)
		str = ft_strjoin("-", str);
	if (mod.precision == 0 && ft_strchr(get, '.'))
	{
		dot = ft_strchr(str, '.');
		str = ft_strsub(str, 0, my_strlen(str) - my_strlen(dot));
	}
	if (mod.width)
		str = handle_int_width(str, mod);
	if ((mod.flag_plus || mod.flag_space) && g_nb >= 0)
		handle_all_flags(value, &str, mod);
	ft_putstr(str);
	*value += my_strlen(str);
}
