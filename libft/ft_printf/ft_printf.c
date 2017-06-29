/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 23:49:14 by alcornea          #+#    #+#             */
/*   Updated: 2017/01/11 16:48:26 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_len(const char *format)
{
	int i;

	i = 1;
	while (ft_strchr(FLAGS, format[i]) && format[i])
		i++;
	if (ft_strchr(SPECIFIERS, format[i]) && format[i])
		return (i + 1);
	else if ((format[i] == '%') && format[i])
		return (i + 1);
	else if (ft_isalpha(format[i]) && format[i])
		return (i + 1);
	else
		return (i);
}

void	check_after_percent(const char *format, int *i, int *value, va_list arg)
{
	int		len;
	char	*get;

	if (check_valid(format + *i))
	{
		len = get_len(format + *i);
		get = ft_strsub(format, *i, len);
		choose_conversion(get, arg, len, value);
		*i = *i + len;
		ft_strdel(&get);
	}
	else
	{
		*i = *i + 1;
		while (ft_strchr(FLAGS, format[*i]) && format[*i])
			*i = *i + 1;
	}
}

int		process_format(const char *format, va_list arg)
{
	int i;
	int value;

	i = 0;
	value = 0;
	while (format[i])
	{
		if (format[i] == '%')
			check_after_percent(format, &i, &value, arg);
		else
		{
			ft_putchar(format[i]);
			value++;
			i++;
		}
	}
	return (value);
}

int		ft_printf(const char *format, ...)
{
	va_list	arg;
	int		value;

	value = 0;
	va_start(arg, format);
	value = process_format(format, arg);
	va_end(arg);
	return (value);
}
