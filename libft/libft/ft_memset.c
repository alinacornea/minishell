/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:50:41 by alcornea          #+#    #+#             */
/*   Updated: 2017/01/08 22:40:52 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		*(unsigned char*)(dest + i) = (unsigned char)c;
		i++;
	}
	return (dest);
}
