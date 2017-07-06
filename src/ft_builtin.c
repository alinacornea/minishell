/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 16:24:28 by alcornea          #+#    #+#             */
/*   Updated: 2017/06/21 16:25:21 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_dup_builtin(char **envar)
{
	int		i;
	char	**tmp;

	i = 0;
	if (!(tmp = (char **)malloc(sizeof(char *) * (ft_strllen(envar) + 2))))
		return (NULL);
	while (envar[i])
	{
		tmp[i] = ft_strdup(envar[i]);
		// printf("tmp[i]%s\n", tmp[i]);
		// printf("envar[i]%s\n", envar[i]);
		i++;
	}
	envar ? free_tab(envar) : (0);
	return (tmp);
}

char	**ft_setsenv(char **envar, char *arg1, char *arg2)
{
	int i;
	int len;

	i = 0;
	len = ft_strllen(envar);
	while (ft_strncmp(envar[i], arg1, ft_strlen(arg1)) && i < len - 1)
		i++;
	if ((i + 1) == len)
	{
		envar = ft_dup_builtin(envar);
		envar[i + 1] = ft_strdup(arg1);
		envar[i + 1] = ft_strjoin(envar[i + 1], "=");
		envar[i + 1] = ft_strjoin(envar[i + 1], arg2);
		// printf("envar[i + 1]%s\n", envar[i + 1]);
		free(arg1);
		free(arg2);
		return (envar);
	}
	return (envar);
}

char	**ft_seteqenv(char **envar, char *arg1)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strllen(envar);
	while (ft_strncmp(envar[i], arg1, ft_strlen(arg1)) && i < len - 1)
		i++;
	if ((i + 1) == len)
	{
		envar = ft_dup_builtin(envar);
		envar[i + 1] = ft_strdup(arg1);
		(!ft_strchr(arg1, '=')) ? envar[i + 1] = ft_strcat(envar[i + 1], "=")
		: NULL;
		ft_strdel(&arg1);
	}
	return (envar);
}

char	**ft_builtin(char **arg, char **envar)
{
	int j;

	if (arg[1] && !ft_strcmp(arg[0], "setenv") && ft_checkarg(arg))
	{
		(arg[2]) ? (envar = ft_setsenv(envar, arg[1], arg[2])) :
		(envar = ft_seteqenv(envar, arg[1]));
	}
	if (ft_strcmp(arg[0], "env") == 0)
		ft_envdisplay(envar);
	if (!ft_strncmp(arg[0], "unsetenv", ft_strlen("unsetenv")))
	{
		j = 1;
		if (ft_compare(envar, arg[j]) != -1)
		{
			while (arg[j])
			{
				envar = ft_unsetenv(envar, arg[j]);
				j++;
			}
		}
	}
	arg ? free(arg) : (0);
	arg[0] ? free(arg[0]) : (0);
	return (envar);
}
