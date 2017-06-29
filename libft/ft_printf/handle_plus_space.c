/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_plus_space.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 23:49:14 by alcornea          #+#    #+#             */
/*   Updated: 2017/01/11 16:48:26 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_int_precision(char *str, t_arg mod)
{
	char	*tmp;
	int		size;
	char	*tmp2;

	size = mod.precision - my_strlen(str);
	if (mod.precision > my_strlen(str))
	{
		if (mod.flag_space && !(mod.width > mod.precision))
			size = size + 1;
		tmp = ft_memalloc(size + 1);
		tmp = ft_memset(tmp, '0', size);
		tmp2 = ft_strjoin(tmp, str);
		free(tmp);
		str = tmp2;
	}
	return (str);
}

void	handle_flag_plus(int *value, char **str, t_arg mod)
{
	char *f;

	f = ft_itoa_base(g_nb, 10);
	if (mod.width > my_strlen(f) && g_nb >= 0 &&
			!mod.precision && (!mod.flag_plus || mod.flag_zero))
		*str[0] = '+';
	else if (mod.width < my_strlen(f))
	{
		ft_putchar('+');
		*value += 1;
	}
	else if (mod.width && mod.flag_minus)
	{
		ft_putchar('+');
		*value += 1;
	}
	free(f);
}

void	handle_flag_space(int *value, char **str, t_arg mod)
{
	char *f;

	f = ft_itoa_base(g_nb, 10);
	if (mod.width > my_strlen(f) && g_nb >= 0 &&
			mod.precision > mod.width && !mod.flag_space)
		*str[0] = ' ';
	else if (mod.width > my_strlen(f) && g_nb >= 0 &&
		mod.flag_space)
		*str[0] = ' ';
	else if (!mod.flag_space)
	{
		ft_putchar(' ');
		*value += 1;
	}
	else if (!mod.width)
	{
		ft_putchar(' ');
		*value += 1;
	}
	free(f);
}

void	handle_all_flags(int *value, char **str, t_arg mod)
{
	if (mod.flag_plus && g_nb >= 0)
		handle_flag_plus(value, str, mod);
	else if (mod.flag_space && g_nb >= 0)
		handle_flag_space(value, str, mod);
}
