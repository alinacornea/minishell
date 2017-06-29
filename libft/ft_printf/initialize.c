/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 23:49:14 by alcornea          #+#    #+#             */
/*   Updated: 2017/01/11 16:48:26 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_valid(const char *str)
{
	int i;

	i = 1;
	while (ft_strchr(FLAGS, str[i]) && str[i])
		i++;
	if (ft_strchr(SPECIFIERS, str[i]) && str[i])
		return (1);
	else if ((str[i] == '%') && str[i])
		return (1);
	else if (ft_isalpha(str[i]) && str[i])
		return (1);
	return (0);
}

void	check_length_modifiers(t_arg *mod, char *get)
{
	int i;

	i = 0;
	while (get[i])
	{
		if (get[i] == 'h' && get[i + 1] == 'h')
		{
			mod->len_hh = 1;
			i++;
		}
		else if (get[i] == 'h')
			mod->len_h = 1;
		else if (get[i] == 'l' && get[i + 1] == 'l')
		{
			mod->len_ll = 1;
			i++;
		}
		else if (get[i] == 'l')
			mod->len_l = 1;
		else if (get[i] == 'j')
			mod->len_j = 1;
		else if (get[i] == 'z')
			mod->len_z = 1;
		i++;
	}
}

void	initialize_modifiers(t_arg *mod)
{
	mod->precision = 0;
	mod->width = 0;
	mod->flag_space = 0;
	mod->flag_zero = 0;
	mod->flag_minus = 0;
	mod->flag_plus = 0;
	mod->flag_hash = 0;
	mod->len_hh = 0;
	mod->len_h = 0;
	mod->len_l = 0;
	mod->len_ll = 0;
	mod->len_j = 0;
	mod->len_z = 0;
	mod->hex = 0;
}
