/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 15:14:36 by alcornea          #+#    #+#             */
/*   Updated: 2017/01/15 15:54:58 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		index;
	int		len;
	char	tmp;

	index = 0;
	len = ft_strlen(str) - 1;
	while (index <= len)
	{
		tmp = str[index];
		str[index] = str[len];
		str[len] = tmp;
		index++;
		len--;
	}
	return (str);
}
