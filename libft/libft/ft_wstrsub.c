/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 12:29:45 by alcornea          #+#    #+#             */
/*   Updated: 2017/04/20 12:29:46 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
