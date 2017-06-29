/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:23:50 by alcornea          #+#    #+#             */
/*   Updated: 2017/01/12 15:47:01 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	int		len;
	int		sign;
	long	nb;
	char	*str;

	if (n < 0)
		sign = 1;
	else
		sign = 0;
	len = ft_len(n);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	nb = n;
	if (sign)
		nb = -nb;
	str[len] = '\0';
	len--;
	while (len)
	{
		str[len] = nb % 10 + '0';
		nb = nb / 10;
		len--;
	}
	str[len] = (sign) ? '-' : (nb % 10 + '0');
	return (str);
}
