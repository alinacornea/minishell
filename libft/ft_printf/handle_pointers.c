/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 23:49:14 by alcornea          #+#    #+#             */
/*   Updated: 2017/01/11 16:48:26 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_p_flag_minus(char **str, char **tmp, t_arg mod)
{
	if (mod.width > my_strlen(*str))
	{
		*tmp = ft_memalloc(mod.width - my_strlen(*str) + 1);
		*tmp = ft_memset(*tmp, ' ', mod.width - my_strlen(*str));
		*str = ft_strjoin(*str, *tmp);
	}
}

char	*handle_p_width(char *str, t_arg mod)
{
	char *tmp;

	if (mod.flag_minus)
		handle_p_flag_minus(&str, &tmp, mod);
	else if (mod.flag_zero)
	{
		if (mod.width > my_strlen(str))
		{
			tmp = ft_memalloc(mod.width - my_strlen(str) + 1);
			tmp = ft_memset(tmp, '0', mod.width - my_strlen(str));
			str = ft_strjoin(str, tmp);
		}
	}
	if (mod.width > my_strlen(str))
	{
		tmp = ft_memalloc(mod.width - my_strlen(str) + 1);
		tmp = ft_memset(tmp, ' ', mod.width - my_strlen(str));
		str = ft_strjoin(tmp, str);
	}
	return (str);
}

void	handle_pointers(va_list arg, int *value, char *get, t_arg mod)
{
	void *p;
	char *str;

	p = va_arg(arg, void*);
	str = convert_long_to_ascii((unsigned long)p, 16);
	g_nb = 1;
	str = handle_int_precision(str, mod);
	if (mod.precision == 0 && ft_atoi(str) == 0 && ft_strchr(get, '.'))
		str[0] = '\0';
	str = ft_strjoin("0x", str);
	str = handle_p_width(str, mod);
	ft_putstr(str);
	*value += my_strlen(str);
	free(str);
}
