/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 12:29:13 by alcornea          #+#    #+#             */
/*   Updated: 2017/04/20 12:29:14 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wcharsize(wchar_t wc)
{
	int size;

	size = 0;
	if (wc <= 127)
		size = 1;
	else if (wc <= 2047)
		size = 2;
	else if (wc <= 65535)
		size = 3;
	else if (wc <= 1114111)
		size = 4;
	return (size);
}
