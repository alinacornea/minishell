/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 23:49:14 by alcornea          #+#    #+#             */
/*   Updated: 2017/01/11 16:48:26 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_precision_asterix(t_arg *mod, char *get, va_list arg)
{
	mod->precision = va_arg(arg, int);
	if (mod->precision < 0 && get[my_strlen(get) - 1] == 's')
	{
		mod->precision = -1 * mod->precision;
	}
	else if (mod->precision < 0)
		mod->precision = 0;
}

void	flag_width_asterix(t_arg *mod, va_list arg)
{
	mod->width = va_arg(arg, int);
	if (mod->width < 0)
	{
		mod->width = -1 * mod->width;
		mod->flag_minus = 1;
	}
	else if (mod->width > 0 && mod->flag_zero)
		mod->flag_zero = 0;
}

void	check_width_flags(t_arg *mod, char *get, int *i)
{
	int		j;
	char	*tmp;

	mod->width = ft_atoi(get + *i);
	tmp = ft_itoa(mod->width);
	j = my_strlen(tmp);
	while (j > 1)
	{
		j--;
		(*i)++;
	}
	ft_strdel(&tmp);
}

void	check_precision_flags(t_arg *mod, char *get, int *i)
{
	mod->precision = ft_atoi(get + *i + 1);
	while (ft_isdigit(get[*i + 1]))
		(*i)++;
}

void	check_flags(t_arg *mod, char *get, va_list arg)
{
	int i;

	i = 0;
	while (get[i])
	{
		if (ft_isdigit(get[i]) && get[i] != '0')
			check_width_flags(mod, get, &i);
		else if (get[i] == '.')
			check_precision_flags(mod, get, &i);
		else if (get[i] == '*' && get[i - 1] == '.')
			flag_precision_asterix(mod, get, arg);
		else if (get[i] == '*' && get[i - 1] != '.')
			flag_width_asterix(mod, arg);
		else if (get[i] == '#')
			mod->flag_hash = 1;
		else if (get[i] == '0' && !ft_isdigit(get[i - 1]))
			mod->flag_zero = 1;
		else if (get[i] == '-')
			mod->flag_minus = 1;
		else if (get[i] == '+')
			mod->flag_plus = 1;
		else if (get[i] == ' ')
			mod->flag_space = 1;
		i++;
	}
}
