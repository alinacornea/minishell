/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 00:41:51 by alcornea          #+#    #+#             */
/*   Updated: 2017/01/11 00:51:16 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		t1;
	size_t		t2;
	int			j;

	i = ft_strlen(dst);
	j = 0;
	t1 = ft_strlen(dst);
	t2 = ft_strlen(src);
	if (size < t1 + 1)
		return (t2 + size);
	if (size > t1 + 1)
	{
		while (i < size - 1)
			*(dst + i++) = *(src + j++);
		*(dst + i) = '\0';
	}
	return (t1 + t2);
}
