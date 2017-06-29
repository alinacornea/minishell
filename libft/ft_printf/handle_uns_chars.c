/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_uns_chars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 23:49:14 by alcornea          #+#    #+#             */
/*   Updated: 2017/01/11 16:48:26 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hex_unchar_len(va_list arg, int *value, char *get, t_arg mod)
{
	unsigned char	c;
	unsigned int	num;
	char			*str;

	c = va_arg(arg, unsigned int);
	if (!mod.hex)
		str = ft_itoa_base(c, 16);
	else
		str = ft_itoa_hex_base(c, 16);
	g_nb = 1;
	num = c;
	str = handle_int_precision(str, mod);
	if (mod.precision == 0 && num == 0 && ft_strchr(get, '.'))
		str[0] = '\0';
	str = handle_int_width(str, mod);
	ft_putstr(str);
	*value += my_strlen(str);
	free(str);
}

void	octal_unchar_len(va_list arg, int *value, char *get, t_arg mod)
{
	unsigned char	c;
	unsigned int	num;
	char			*str;

	c = va_arg(arg, int);
	str = ft_itoa_base(c, 8);
	g_nb = 1;
	num = c;
	str = handle_int_precision(str, mod);
	if (mod.precision == 0 && num == 0 && ft_strchr(get, '.'))
		str[0] = '\0';
	str = handle_int_width(str, mod);
	ft_putstr(str);
	*value += my_strlen(str);
	free(str);
}

void	unsign_char_len(va_list arg, int *value, char *get, t_arg mod)
{
	unsigned char	c;
	unsigned int	num;
	char			*str;

	c = va_arg(arg, int);
	str = ft_itoa_base(c, 10);
	g_nb = 1;
	num = c;
	str = handle_int_precision(str, mod);
	if (mod.precision == 0 && num == 0 && ft_strchr(get, '.'))
		str[0] = '\0';
	str = handle_int_width(str, mod);
	ft_putstr(str);
	*value += my_strlen(str);
	free(str);
}

void	handle_sign_char(va_list arg, int *value, char *get, t_arg mod)
{
	signed char	c;
	int			num;
	char		*str;

	c = va_arg(arg, int);
	num = c;
	if (num == 0)
		str = "0";
	else
		str = convert_int_to_ascii(c, 10);
	if (mod.precision)
		str = handle_int_precision(str, mod);
	if ((num < 0 && !mod.precision && !mod.width) || (num < 0 &&
		mod.precision))
		str = ft_strjoin("-", str);
	if (mod.precision == 0 && num == 0 && ft_strchr(get, '.'))
		str[0] = '\0';
	if (mod.width)
		str = handle_int_width(str, mod);
	if ((mod.flag_plus || mod.flag_space) && num >= 0)
		handle_all_flags(value, &str, mod);
	ft_putstr(str);
	*value += my_strlen(str);
}
