/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 14:34:22 by alcornea          #+#    #+#             */
/*   Updated: 2017/01/09 13:28:50 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *c1;
	char *c2;

	c1 = (char *)dst;
	c2 = (char *)src;
	if (n == 0 || dst == src)
		return (dst);
	while (--n)
		*c1++ = *c2++;
	*c1 = *c2;
	return (dst);
}
