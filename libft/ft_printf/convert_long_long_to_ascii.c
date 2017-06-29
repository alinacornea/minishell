/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_ascii.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 12:27:09 by alcornea          #+#    #+#             */
/*   Updated: 2017/04/20 12:27:12 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*convert_long_long_to_ascii(long long num, int base)
{
	int					i;
	unsigned long long	sign;
	static char			buf[32] = "0";

	i = 30;
	if (num == 0)
		return (ft_strdup("0"));
	if (num < 0)
	{
		sign = -num;
		while (sign > 0 && i > 0)
		{
			buf[i--] = "0123456789abcdef"[sign % base];
			sign /= base;
		}
		buf[i] = '-';
		return (buf + i + 1);
	}
	while (num > 0 & i > 0)
	{
		buf[i] = "0123456789abcdef"[num % base];
		num /= base;
		i--;
	}
	return (buf + i + 1);
}
