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

void init_struct(char **envar, t_cd *cd)
{
	cd->tmp = NULL;
	cd->fr = NULL;
	cd->pwd = find_arg(envar, "PWD");
	cd->old = find_arg(envar, "OLDPWD");
	cd->tmp2 = ft_strchr(envar[cd->pwd], '=');
	cd->cwd = getcwd(cd->tmp, 2048);
	cd->param = get_param(envar[cd->pwd]);
}

void	ft_printlast(char **envar)
{
	int		oldpwd;
	char	*str;

	str = NULL;
	oldpwd = find_arg(envar, "OLDPWD");
	if (ft_strlen(envar[oldpwd]) > 26)
		str = ft_strsub(envar[oldpwd], 27, ft_strlen(envar[oldpwd]) - 27);
	str ? ft_printf("~%s\n", str) : ft_printf("~\n");
	str ? free(str) : (0);
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
