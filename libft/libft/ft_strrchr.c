/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 13:37:44 by alcornea          #+#    #+#             */
/*   Updated: 2017/01/08 13:40:29 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *str;

	str = (char *)s + ft_strlen(s);
	while (*str != c)
	{
		if (str == s)
		{
			return (NULL);
		}
		str--;
	}
	return (str);
}
