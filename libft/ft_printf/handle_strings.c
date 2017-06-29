/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_strings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 23:49:14 by alcornea          #+#    #+#             */
/*   Updated: 2017/01/11 16:48:26 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_s_width(char **str, t_arg mod)
{
	int		len;
	char	*tmp;

	len = my_strlen(*str);
	if (mod.width > len)
	{
		if (mod.flag_minus)
			*str = ft_strncat(*str, " ", mod.width - len);
		else
		{
			tmp = ft_memalloc(mod.width - len + 1);
			tmp = ft_memset(tmp, ' ', mod.width - len);
			*str = ft_strcat(tmp, *str);
			ft_strdel(&tmp);
		}
	}
}

void	ft_process_s_flag_zero(char **str, t_arg mod)
{
	char	*tmp;

	if (mod.width > my_strlen(*str))
	{
		tmp = ft_memalloc(mod.width - my_strlen(*str) + 1);
		tmp = ft_memset(tmp, '0', mod.width - my_strlen(*str));
		*str = ft_strjoin(tmp, *str);
		ft_strdel(&tmp);
	}
}

void	null_str_precision(int *value, char *get, t_arg mod)
{
	char *str;

	str = ft_strdup("(null)");
	if (mod.precision < my_strlen(str))
		str = ft_strsub(str, 0, mod.precision);
	if (mod.precision == 0 && ft_strchr(get, '.'))
		str = "";
	if (mod.width)
	{
		if (mod.flag_zero)
			ft_process_s_flag_zero(&str, mod);
		ft_process_s_width(&str, mod);
	}
	ft_putstr(str);
	*value += my_strlen(str);
	ft_strdel(&str);
}

void	ft_process_s_val_str(char *str, int *value, char *get, t_arg mod)
{
	if (mod.precision && mod.precision < my_strlen(str))
		str = ft_strsub(str, 0, mod.precision);
	if (mod.precision == 0 && ft_strchr(get, '.'))
		str = ft_strdup("");
	if (mod.width)
	{
		if (mod.flag_zero)
			ft_process_s_flag_zero(&str, mod);
		ft_process_s_width(&str, mod);
	}
	ft_putstr(str);
	*value += my_strlen(str);
}

void	handle_strings(va_list arg, int *value, char *get, t_arg mod)
{
	char *str;

	if (mod.len_l)
		handle_ls_string(arg, value, get, mod);
	else
	{
		str = va_arg(arg, char *);
		if (str)
			ft_process_s_val_str(str, value, get, mod);
		else if (!str && ft_strchr(get, '.'))
			null_str_precision(value, get, mod);
		else
		{
			ft_putstr("(null)");
			*value += 6;
		}
	}
}
