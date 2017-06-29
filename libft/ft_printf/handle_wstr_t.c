/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wstr_t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 23:49:14 by alcornea          #+#    #+#             */
/*   Updated: 2017/01/11 16:48:26 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_wstrlen(const wchar_t *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_wstrsize(wchar_t *wstr)
{
	int size;
	int i;

	i = 0;
	size = 0;
	while (wstr[i])
	{
		if (wstr[i] <= 127)
			size += 1;
		else if (wstr[i] <= 2047)
			size += 2;
		else if (wstr[i] <= 65535)
			size += 3;
		else if (wstr[i] <= 1114111)
			size += 4;
		i++;
	}
	return (size);
}

wchar_t	*ft_wstrsub(wchar_t *s, unsigned int start, size_t len)
{
	wchar_t	*dst;
	size_t	i;
	int		len2;

	len2 = (int)len;
	if (!(dst = (wchar_t*)malloc(sizeof(*dst) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = s[start + i];
		i++;
		len = len - ft_wcharsize(s[i]);
	}
	dst[i] = '\0';
	if (ft_wstrsize(dst) + ft_wcharsize(s[start + i]) <= len2)
	{
		dst[i] = s[start + i];
		dst[i + 1] = '\0';
	}
	return (dst);
}

wchar_t	*handle_ls_width(wchar_t *wstr, t_arg mod)
{
	wchar_t	*tmp;
	int		size;

	size = mod.width - ft_wstrsize(wstr);
	if (mod.width > ft_wstrsize(wstr))
	{
		tmp = (wchar_t*)malloc(sizeof(*tmp) * size + 1);
		tmp[size] = '\0';
		if (mod.flag_minus)
		{
			tmp = ft_wmemset(tmp, L' ', size);
			wstr = ft_wstrjoin(wstr, tmp);
		}
		else if (mod.flag_zero)
		{
			tmp = ft_wmemset(tmp, L'0', size);
			wstr = ft_wstrjoin(tmp, wstr);
		}
		else
		{
			tmp = ft_wmemset(tmp, L' ', size);
			wstr = ft_wstrjoin(tmp, wstr);
		}
	}
	return (wstr);
}

void	handle_ls_string(va_list arg, int *value, char *get, t_arg mod)
{
	wchar_t *wstr;
	int		i;

	i = 0;
	wstr = va_arg(arg, wchar_t *);
	if (wstr)
	{
		if (mod.precision && mod.width < ft_wstrsize(wstr))
			wstr = ft_wstrsub(wstr, 0, mod.precision);
		if (mod.precision == 0 && ft_strchr(get, '.'))
			wstr = ft_wstrdup(L"");
		if (mod.width)
			wstr = handle_ls_width(wstr, mod);
		while (wstr[i])
		{
			ft_putwchar(wstr[i]);
			*value += ft_wcharsize(wstr[i]);
			i++;
		}
	}
	else
	{
		ft_putstr("(null)");
		*value += 6;
	}
}
