/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 23:49:14 by alcornea          #+#    #+#             */
/*   Updated: 2017/04/18 00:59:59 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_negative_num(char *str, t_arg mod)
{
	char	*tmp;
	int		size;
	char	*tmp2;

	size = mod.width - my_strlen(str);
	if (mod.flag_minus)
	{
		tmp = ft_memalloc(size);
		tmp = ft_memset(tmp, ' ', size - 1);
		tmp2 = ft_strjoin(str, tmp);
		free(tmp);
		str = tmp2;
		if (!mod.precision)
			str = ft_strjoin("-", str);
	}
	else if (mod.width > my_strlen(str) && g_nb < 0)
	{
		if (!mod.precision)
			str = ft_strjoin("-", str);
		size = mod.width - my_strlen(str);
		tmp = ft_memalloc(size + 1);
		tmp = ft_memset(tmp, ' ', size);
		str = ft_strjoin(tmp, str);
	}
	return (str);
}

char	*handle_width_flag_minus(char *str, t_arg mod)
{
	char	*tmp;
	char	*tmp2;

	if (mod.width > my_strlen(str) && !mod.precision && g_nb < 0)
		str = handle_negative_num(str, mod);
	else if (mod.width > my_strlen(str) && !mod.precision && g_nb >= 0)
	{
		tmp = ft_memalloc(mod.width - my_strlen(str) + 1);
		tmp = ft_memset(tmp, ' ', mod.width - my_strlen(str));
		tmp2 = ft_strjoin(str, tmp);
		free(tmp);
		str = tmp2;
		if (mod.flag_plus)
			str[my_strlen(str) - 1] = '\0';
	}
	else if (mod.width > my_strlen(str) && mod.precision < mod.width)
	{
		tmp = ft_memalloc(mod.width - my_strlen(str) + 1);
		tmp = ft_memset(tmp, ' ', mod.width - my_strlen(str));
		str = ft_strjoin(str, tmp);
		if (mod.flag_plus && g_nb > 0)
			str[my_strlen(str) - 1] = '\0';
	}
	return (str);
}

char	*ft_setlloc(char *str, char *tmp, t_arg mod)
{
	int		size;
	char	*tmp2;

	tmp2 = NULL;
	size = mod.width - my_strlen(str);
	tmp = ft_memalloc(size + 1);
	tmp = ft_memset(tmp, ' ', size);
	tmp2 = ft_strjoin(tmp, str);
	free(tmp);
	str = tmp2;
	return (str);
}

char	*handle_width_flag_zero(char *tmp, char *str, t_arg mod)
{
	char *tmp2;

	if (mod.width > my_strlen(str) && !mod.precision && g_nb >= 0)
	{
		tmp = ft_memalloc(mod.width - my_strlen(str) + 1);
		tmp = ft_memset(tmp, '0', mod.width - my_strlen(str));
		tmp2 = ft_strjoin(tmp, str);
		free(tmp);
		str = tmp2;
		if (mod.flag_hash)
			str[1] = mod.hex ? 'X' : 'x';
	}
	else if (mod.width > my_strlen(str) && !mod.precision && g_nb < 0)
	{
		tmp = ft_memalloc(mod.width - my_strlen(str) + 1);
		tmp = ft_memset(tmp, '0', mod.width - my_strlen(str) - 1);
		str = ft_strjoin(tmp, str);
		if (!mod.precision)
			str = ft_strjoin("-", str);
	}
	else if (mod.width > my_strlen(str) && mod.width && mod.precision)
		str = ft_setlloc(str, tmp, mod);
	return (str);
}

char	*handle_int_width(char *str, t_arg mod)
{
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	if (mod.flag_minus)
		str = handle_width_flag_minus(str, mod);
	else if (mod.flag_zero && !mod.flag_minus)
		str = handle_width_flag_zero(tmp, str, mod);
	else if (mod.width > my_strlen(str) && g_nb < 0)
		str = handle_negative_num(str, mod);
	else if (mod.width > my_strlen(str) && g_nb >= 0)
	{
		if (mod.flag_plus)
			str = ft_strjoin("+", str);
		tmp2 = ft_setlloc(str, tmp, mod);
		free(tmp);
		str = tmp2;
	}
	else if (mod.width <= my_strlen(str) && g_nb < 0 && !mod.flag_minus)
	{
		if (!mod.precision && g_nb < 0)
			str = ft_strjoin("-", str);
	}
	return (str);
}
