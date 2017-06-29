/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_modifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 23:49:14 by alcornea          #+#    #+#             */
/*   Updated: 2017/01/11 16:48:26 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	choose_type2(char *get, va_list arg, int *value, t_arg mod)
{
	int len;

	len = my_strlen(get);
	if (get[len - 1] == 'o')
		handle_octal(arg, value, get, mod);
	else if (get[len - 1] == 'O')
		octal_long_len(arg, value, get, mod);
	else if (get[len - 1] == 'u')
		handle_uns_int(arg, value, get, mod);
	else if (get[len - 1] == 'C' || (get[len - 1] == 'c' && mod.len_l))
		handle_lc_char(arg, value);
	else if (get[len - 1] == 'S')
		handle_ls_string(arg, value, get, mod);
	else if (get[len - 1] == 'f' || get[len - 1] == 'F')
		handle_float(arg, value, get, mod);
	else if (get[len - 1] == 'U')
		unsigned_l_len(arg, value, get, mod);
	else if (get[len - 1] == '%')
		handle_percent(value, mod);
	else
		invalid_conversion_type(value, get, mod);
}

void	choose_conversion(char *get, va_list arg, int len, int *value)
{
	t_arg mod;

	initialize_modifiers(&mod);
	check_length_modifiers(&mod, get);
	check_flags(&mod, get, arg);
	if (get[len - 1] == 's')
		handle_strings(arg, value, get, mod);
	else if (get[len - 1] == 'd' || get[len - 1] == 'i')
		handle_integers(arg, value, get, mod);
	else if (get[len - 1] == 'D')
		long_length_d(arg, value, get, mod);
	else if (get[len - 1] == 'c' && !mod.len_l)
		handle_chars(arg, value, mod);
	else if (get[len - 1] == 'p')
		handle_pointers(arg, value, get, mod);
	else if (get[len - 1] == 'x')
		handle_hex(arg, value, get, mod);
	else if (get[len - 1] == 'X')
	{
		mod.hex = 1;
		handle_hex(arg, value, get, mod);
	}
	else
		choose_type2(get, arg, value, mod);
}
