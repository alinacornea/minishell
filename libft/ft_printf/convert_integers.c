/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_integers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 23:49:14 by alcornea          #+#    #+#             */
/*   Updated: 2017/04/18 03:10:59 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define FREEIF(x) if(x != '\0') free(x)

char	*check_negative(int num, char *str)
{
	if (num == -2147483648)
		str = ft_strcat("-", "2147483648");
	else
		str = ft_strcat("-", str);
	return (str);
}

void	convert_width_int(int num, int *value, char *str, t_arg mod)
{
	char	*tmp2;

	tmp2 = NULL;
	if (mod.width > my_strlen(str))
	{
		tmp2 = handle_int_width(str, mod);
		str = tmp2;
	}
	if ((mod.flag_plus || mod.flag_space) && num >= 0)
		handle_all_flags(value, &str, mod);
	ft_putstr(str);
	*value += my_strlen(str);
	FREEIF(tmp2);
}

void	convert_integers(va_list arg, int *value, char *get, t_arg mod)
{
	int		num;
	char	*str;
	char	*tmp;

	num = va_arg(arg, int);
	g_nb = num;
	str = convert_int_to_ascii(num, 10);
	tmp = NULL;
	if (mod.precision > my_strlen(str))
	{
		tmp = handle_int_precision(str, mod);
		str = tmp;
	}
	if (num < 0 && ((!mod.precision && !mod.width) || mod.precision))
		str = check_negative(num, str);
	if (mod.precision == 0 && num == 0 && ft_strchr(get, '.'))
		str[0] = '\0';
	convert_width_int(num, value, str, mod);
	FREEIF(tmp);
}
