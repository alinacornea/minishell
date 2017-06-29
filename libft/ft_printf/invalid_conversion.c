/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 23:49:14 by alcornea          #+#    #+#             */
/*   Updated: 2017/01/11 16:48:26 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_percent_width(char **str, t_arg mod)
{
	char *tmp;

	if (mod.width > my_strlen(*str))
	{
		if (mod.flag_minus)
		{
			tmp = ft_memalloc(mod.width - my_strlen(*str) + 1);
			tmp = ft_memset(tmp, ' ', mod.width - my_strlen(*str));
			*str = ft_strcat(*str, tmp);
		}
		else if (mod.flag_zero)
		{
			tmp = ft_memalloc(mod.width - my_strlen(*str) + 1);
			tmp = ft_memset(tmp, '0', mod.width - my_strlen(*str));
			*str = ft_strcat(tmp, *str);
		}
		else
		{
			tmp = ft_memalloc(mod.width - my_strlen(*str) + 1);
			tmp = ft_memset(tmp, ' ', mod.width - my_strlen(*str));
			*str = ft_strcat(tmp, *str);
		}
		ft_strdel(&tmp);
	}
}

void	handle_percent(int *value, t_arg mod)
{
	char *str;

	str = ft_strdup("%");
	check_percent_width(&str, mod);
	ft_putstr(str);
	*value += my_strlen(str);
	ft_strdel(&str);
}

void	invalid_conversion_type(int *value, char *get, t_arg mod)
{
	char	*str;
	int		len;

	len = my_strlen(get);
	str = (char*)malloc(sizeof(*str + 1));
	str[0] = get[len - 1];
	str[1] = '\0';
	check_percent_width(&str, mod);
	ft_putstr(str);
	*value += my_strlen(str);
	ft_strdel(&str);
}
