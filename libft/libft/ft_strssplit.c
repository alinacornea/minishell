/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strssplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 16:24:28 by alcornea          #+#    #+#             */
/*   Updated: 2017/06/21 16:25:21 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' ||
		c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

static int		ft_count(char const *s)
{
	int	cmp;
	int	i;

	cmp = 0;
	i = 0;
	while (*s)
	{
		if (i == 1 && ft_isspace(*s))
			i = 0;
		if (i == 0 && !ft_isspace(*s))
		{
			i = 1;
			cmp++;
		}
		s++;
	}
	return (cmp);
}

static int		ft_len(char const *s)
{
	int	len;

	len = 0;
	while (*s && !ft_isspace(*s))
	{
		s++;
		len++;
	}
	return (len);
}

char			**ft_strssplit(char const *s)
{
	char	**t;
	int		i;
	int		word_nb;

	if (!s)
		return (NULL);
	i = 0;
	word_nb = ft_count(s);
	t = (char **)malloc(sizeof(char *) * (ft_count(s) + 1));
	if (t == NULL)
		return (NULL);
	while (word_nb--)
	{
		while (*s && ft_isspace(*s))
			s++;
		t[i] = ft_strsub((const char *)s, 0, ft_len(s));
		if (t[i] == NULL)
			return (NULL);
		s = s + ft_len(s);
		i++;
	}
	t[i] = NULL;
	return (t);
}
