/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 15:20:58 by alcornea          #+#    #+#             */
/*   Updated: 2017/01/08 15:08:04 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*cur;
	size_t		i;

	cur = (const char *)s;
	i = -1;
	while (++i < n)
	{
		if (*(cur + i) == (char)c)
			return ((void *)cur + i);
	}
	return (NULL);
}
