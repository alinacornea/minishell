/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forkexe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 16:24:28 by alcornea          #+#    #+#             */
/*   Updated: 2017/06/21 16:25:21 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_compare(char **envar, char *path)
{
	int i;

	i = 0;
	while (envar[i] && path)
	{
		if (!ft_strncmp(envar[i], path, ft_strlen(path)))
			return (i);
		i++;
	}
	return (-1);
}

char	*get_path(char *arg, char *tab)
{
	char *tmp;

	tmp = ft_strcat(tab, "/");
	tmp = ft_strcat(tmp, arg);
	return (tmp);
}

char	*get_param(char *str)
{
	size_t	j;
	size_t	i;
	char	*param;

	i = 0;
	j = 0;
	param = NULL;
	while (str[i] != '=')
		i++;
	i++;
	param = (char *)malloc(sizeof(char) * (ft_strlen(str) - i));
	while (str[i] && i < ft_strlen(str))
	{
		param[j] = str[i];
		i++;
		j++;
	}
	param[j] = '\0';
	return (param);
}

char	**set_tab(char **envar, char **arg)
{
	char	**tab;
	int		value;
	char	*param;

	value = ft_compare(envar, "PATH=");
	if (value != -1)
	{
		param = get_param(envar[value]);
		tab = ft_strsplit(param, ':');
		param ? ft_strdel(&param) : (0);
		return (tab);
	}
	else
		ft_printf("%s%s\n", arg[0], NOT);
	return (NULL);
}

void	ft_forkexe(char **arg, char **envar)
{
	t_exe exe;

	exe.i = -1;
	exe.pid = fork();
	(exe.pid > 0) ? wait(&exe.w) : (0);
	if (exe.pid == 0)
	{
		execve(arg[0], arg, envar);
		if (ft_getbuiltin(arg) < 0)
		{
			exe.tab = set_tab(envar, arg);
			while (exe.tab[++exe.i])
			{
				exe.tmp = get_path(arg[0], exe.tab[exe.i]);
				execve(exe.tmp, arg, envar);
			}
			(!ft_strcmp(arg[0], "clear")) ? ft_printf("%s", CL) :
			ft_printf("%s%s\n", arg[0], NOT);
			free_tab(exe.tab);
		}
		exit(0);
	}
	free_tab(arg);
}
