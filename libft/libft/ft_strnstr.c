/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 14:48:39 by alcornea          #+#    #+#             */
/*   Updated: 2017/01/08 14:53:33 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t n;

	if (*little == '\0')
		return ((char*)big);
	n = ft_strlen(little);
	while (*big != '\0' && len-- >= n)
	{
		if (*big == *little && ft_memcmp(big, little, n) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
