/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 16:24:28 by alcornea          #+#    #+#             */
/*   Updated: 2017/06/21 16:25:21 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_env(char **env)
{
	int		i;
	char	**tmp;

	i = 0;
	if (!(tmp = malloc(sizeof(char*) * ft_strllen(env) + 1)))
		return (NULL);
	while (env[i])
	{
		tmp[i] = ft_strdup(env[i]);
		i++;
	}
	return (tmp);
}

int		ft_getbuiltin(char **arg)
{
	if (!ft_strcmp(arg[0], "echo"))
		return (2);
	else if (!ft_strcmp(arg[0], "cd"))
		return (1);
	else if (!ft_strcmp(arg[0], "env"))
		return (0);
	else if (!ft_strcmp(arg[0], "unsetenv"))
		return (0);
	else if (!ft_strcmp(arg[0], "setenv"))
		return (0);
	return (-1);
}

char	**ft_execute(char **arg, char **envar)
{
	if (ft_strcmp(arg[0], "exit") == 0)
	{
		ft_putstr("exit\n");
		free_tab(arg);
		envar ? free_tab(envar) : (0);
		// sleep(20);
		exit(0);
	}
	else if (!ft_getbuiltin(arg))
		envar = ft_builtin(arg, envar);
	else if (ft_getbuiltin(arg) == 1)
		envar = ft_cd(arg, envar);
	else if (ft_getbuiltin(arg) == 2)
		envar = ft_parse_echo(arg, envar);
	else
		ft_forkexe(arg, envar);
	return (envar);
}

int		main(int argc, char **argv, char **env)
{
	int		nb;
	char	line[1024];
	char	**envar;
	char	**arg;

	if (argc && argv && env)
		envar = ft_env(env);
	while (1)
	{
		ft_printf("\033[31m<3 \033[0m");
		nb = read(0, line, 1024);
		if (nb == 0)
		{
			ft_putchar('\n');
			exit(0);
		}
		line[nb - 1] = '\0';
		arg = ft_strsplit(line, ' ');
		!arg[0] ? free(arg) : (0);
		if (arg[0] && env[0])
			envar = ft_execute(arg, envar);
	}
	return (0);
}
