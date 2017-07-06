/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 16:24:28 by alcornea          #+#    #+#             */
/*   Updated: 2017/06/21 16:25:21 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		find_arg(char **envar, char *str)
{
	int i;

	i = 0;
	while (envar[i] != NULL && str)
	{
		if (!ft_strncmp(envar[i], str, ft_strlen(str)))
			return (i);
		i++;
	}
	return (-1);
}

void	init_struct(char **envar, t_cd *cd)
{
	cd->tmp = NULL;
	cd->fr = NULL;
	cd->pwd = 0;
	cd->old = 0;
	cd->pwd = find_arg(envar, "PWD");
	cd->old = find_arg(envar, "OLDPWD");
	cd->cwd = getcwd(cd->tmp, 2048);
	cd->param = get_param(envar[cd->pwd]);
}

void	ft_envdisplay(char **envar)
{
	int i;

	i = 0;
	while (envar[i] && i < ft_strllen(envar))
	{
		ft_printf("%s\n", envar[i]);
		i++;
	}
}

int		ft_checkarg(char **arg)
{
	int i;

	i = 0;
	while (arg[i])
	{
		if (ft_strllen(arg) > 3)
		{
			ft_printf("%s\n", ARGS);
			return (0);
			break ;
		}
		else if (ft_isdigit(arg[i][0]) && ft_strllen(arg) <= 3)
		{
			ft_printf("%s\n", LETTER);
			return (0);
			break ;
		}
		i++;
	}
	return (1);
}
