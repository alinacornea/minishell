/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 16:24:28 by alcornea          #+#    #+#             */
/*   Updated: 2017/06/21 16:25:21 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_struct(char **envar, t_cd *cd)
{
	cd->pwd = 0;
	cd->old = 0;
	cd->fr = NULL;
	getcwd(cd->cwd, 2048);
	cd->pwd = find_arg(envar, "PWD");
	cd->old = find_arg(envar, "OLDPWD");
	cd->home = get_param(envar[find_arg(envar, "HOME")]);
}

int		check_access(char **arg, char **envar)
{
	if (access(arg[1], F_OK) == -1 && envar[0])
	{
		ft_printf("%s %s\n", FILE, arg[1]);
		return (-1);
	}
	else if (access(arg[1], X_OK) == -1 && envar[0])
	{
		ft_printf("%s %s\n", DEN, arg[1]);
		return (-1);
	}
	return (0);
}

char	*ft_printlast(char **envar, char *home, t_cd *cd)
{
	int		n;
	char	*tmp;

	n = 0;
	tmp = get_param(envar[cd->old]);
	if ((n = ft_strlnstr(tmp, home)) < 0)
		ft_printf("~%s\n", tmp);
	else
		ft_printf("~%s\n", tmp + n);
	return (tmp);
}

char	**ft_home(char **envar, t_cd *cd)
{
	char	cwd[1024];

	getcwd(cwd, 1024);
	if (cd->pwd != -1)
	{
		envar[cd->old] ? free(envar[cd->old]) : (0);
		envar[cd->old] = ft_strjoin("OLDPWD=", cd->cwd);
		cd->fr = envar[cd->pwd];
		envar[cd->pwd] = ft_strjoin("PWD=", cwd);
	}
	return (envar);
}

char	**ft_cd(char **arg, char **envar)
{
	t_cd *cd;
	char *new;

	new = NULL;
	cd = ft_memalloc(sizeof(t_cd));
	init_struct(envar, cd);
	if (!arg[1] || (!ft_strncmp(arg[1], "~", 1)))
	{
		if (arg[1])
			new = ft_strjoin(cd->home, arg[1] + 1);
		else
			new = ft_strdup(cd->home);
	}
	else if (!ft_strncmp(arg[1], "-", 1))
		new = ft_printlast(envar, cd->home, cd);
	else
		new = ft_strdup(arg[1]);
	if (chdir(new) < 0)
		check_access(arg, envar);
	else
		ft_home(envar, cd);
	new ? ft_strdel(&new) : (0);
	free_struct(cd, arg);
	return (envar);
}
