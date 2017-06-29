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

	value = ft_compare(envar, "PATH");
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
	int i;
	int w;
	char **tab;
	char *tmp;
	pid_t pid;

	i = 0;
	pid = fork();
	tab = set_tab(envar);
	if (pid > 0)
		wait(&w);
	if (pid == 0)
	{
		if (ft_getbuiltin(arg) < 0)
		{
			while (tab[i])
			{
				tmp = get_path(arg[0], tab[i]);
				execve(tmp, arg, envar);
				i++;
			}
			ft_putstr(arg[0]);
			ft_putstr(": Command not found.\n");
		}
	}
	free_tab(tab);
	free_tab(arg);
}
