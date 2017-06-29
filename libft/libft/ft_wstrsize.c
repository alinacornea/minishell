/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 12:50:45 by alcornea          #+#    #+#             */
/*   Updated: 2017/04/20 12:51:47 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wstrsize(wchar_t *wstr)
{
	int size;
	int i;

	i = 0;
	size = 0;
	while (wstr[i])
	{
		if (wstr[i] <= 127)
			size += 1;
		else if (wstr[i] <= 2047)
			size += 2;
		else if (wstr[i] <= 65535)
			size += 3;
		else if (wstr[i] <= 1114111)
			size += 4;
		i++;
	}
	return (size);
}
