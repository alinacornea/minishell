/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 16:24:28 by alcornea          #+#    #+#             */
/*   Updated: 2017/06/21 16:25:21 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_compare(char **envar, char *path)
{
	int i;

	i = 0;
	while (envar[i] && path)
	{
		if (ft_strncmp(envar[i], path, ft_strlen(path)) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char *get_path(char *arg, char *tab)
{
	char *tmp;

	tmp = ft_strcat(tab, "/");
	tmp = ft_strcat(tmp, arg);
	return (tmp);
}

char *get_param(char *str)
{
	int j;
	size_t i;
	char *param;

	i = 0;
	j = 0;
	while (str[i] != '=')
		i++;
	i++;
	param = (char *)malloc(sizeof(char) * (ft_strlen(str) - i));
	while (i < ft_strlen(str))
	{
		param[j] = str[i];
		i++;
		j++;
	}
	return (param);
}

char **set_tab(char **envar)
{
	char **tab;
	int value;
	char *param;

	value = ft_compare(envar, "PATH=");
	param = get_param(envar[value]);
	if (value == 1)
		tab = ft_strsplit("/bin:/usr/bin", ':');
	else
		tab = ft_strsplit(param, ':');
	param ? ft_strdel(&param) : (0);
	return (tab);
}

void ft_forkexe(char **arg, char **envar)
{
	t_exe exe;

	exe.i = 0;
	exe.pid = 1;
	exe.pid = fork();
	exe.tab = set_tab(envar);
	if (exe.pid > 0)
		wait(&exe.w);
	if (exe.pid == 0)
	{
		execve(arg[0], arg, envar);
		if (ft_getbuiltin(arg) < 0)
		{
			while (exe.tab[exe.i])
			{
				exe.tmp = get_path(arg[0], exe.tab[exe.i]);
				execve(exe.tmp, arg, envar);
				exe.i++;
			}
			ft_printf("%s: Command not found.\n", arg[0]);
		}
		free_envar(exe.tab);
		free_tab(arg);
		exit(0);
	}
}
