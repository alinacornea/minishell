/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_chars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 23:49:14 by alcornea          #+#    #+#             */
/*   Updated: 2017/01/11 16:48:26 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_minus_zero_char(unsigned char c, int *value, char *str, t_arg mod)
{
	if (mod.flag_minus && mod.width > 1)
	{
		ft_putchar(c);
		*value = *value + 1;
		str = ft_memalloc(mod.width);
		str = ft_memset(str, ' ', mod.width - 1);
		ft_putstr(str);
		*value += my_strlen(str);
	}
	else if (mod.flag_zero && mod.width > 1)
	{
		str = ft_memalloc(mod.width);
		str = ft_memset(str, '0', mod.width - 1);
		ft_putstr(str);
		*value += my_strlen(str);
		ft_putchar(c);
		*value = *value + 1;
	}
}

void	handle_chars(va_list arg, int *value, t_arg mod)
{
	unsigned char	c;
	char			*tmp;

	tmp = NULL;
	c = va_arg(arg, int);
	if (mod.flag_minus || mod.flag_zero)
		flag_minus_zero_char(c, value, tmp, mod);
	else if (mod.width > 1)
	{
		tmp = ft_memalloc(mod.width - 1 + 1);
		tmp = ft_memset(tmp, ' ', mod.width - 1);
		ft_putstr(tmp);
		*value += my_strlen(tmp);
		ft_putchar(c);
		*value = *value + 1;
	}
	else
	{
		ft_putchar(c);
		*value = *value + 1;
	}
}
