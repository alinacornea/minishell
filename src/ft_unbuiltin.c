/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbuiltin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 16:24:28 by alcornea          #+#    #+#             */
/*   Updated: 2017/06/21 16:25:21 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_tabreallocless(char **envar, int j)
{
	int		i;
	int		k;
	char	**tmp;

	k = -1;
	i = -1;
	if(!(tmp = (char**)malloc(sizeof(char*) * ft_strllen(envar))))
		return (NULL);
	while (envar[++i])
	{
		if (i == j)
			continue ;
		if (envar[i] != NULL)
		{
			tmp[++k] = ft_strdup(envar[i]);
			envar[i] ? free(envar[i]) : (0);
		}
	}
	free(envar);
	tmp[++k] = NULL;
	return (tmp);
}

char	**ft_unsetenv(char **envar, char *param)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	tmp = ft_strjoin(param, "=");
	while (i < ft_strllen(envar))
	{
		if (!ft_strncmp(envar[i], tmp, ft_strlen(tmp)))
			j = i;
		i++;
	}
	free(envar[j]);
	envar = ft_tabreallocless(envar, j);
	free(tmp);
	free(param);
	return (envar);
}
