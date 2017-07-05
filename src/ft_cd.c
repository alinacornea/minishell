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

char	*ft_setnew(char *str, char **arg)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(arg[1]) - 1))))
		return (NULL);
	while (arg[1][i] == '~')
		i++;
	while (i < ft_strlen(arg[1]))
	{
		tmp[j] = arg[1][i];
		j++;
		i++;
	}
	str = ft_strcat(str, tmp);
	tmp ? free(tmp) : (0);
	return (str);
}

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

void	ft_gotodir(char *tmp, char **arg)
{
	char *new;
	char *str;

	if (ft_strcmp(arg[1], "/"))
	{
		str = getcwd(tmp, 2048);
		new = ft_strcat(str, "/");
		new = ft_strcat(new, arg[1]);
		new = ft_strcat(new, "/");
	}
	else
		new = ft_strdup("/");
	chdir(new);
	new ? ft_strdel(&new) : (0);
}

char	**ft_home(char **arg, char **envar, t_cd *cd)
{
	char	*new;

	new = get_param(envar[find_arg(envar, "HOME")]);
	if (arg[1] && ft_strlen(arg[1]) > 1)
	{
		new = ft_setnew(new, arg);
		(access(new, F_OK) == -1) ? ft_printf("%s %s\n", FILE, new) : (0);
	}
	chdir(new);
	if (cd->pwd != -1)
	{
		envar[cd->old] ? free(envar[cd->old]) : (0);
		envar[cd->old] = ft_strjoin("OLDPWD=", cd->param);
		cd->fr = envar[cd->pwd];
		envar[cd->pwd] = ft_strjoin("PWD=", cd->cwd);
	}
	new ? ft_strdel(&new) : (0);
	return (envar);
}

char	**ft_cd(char **arg, char **envar)
{
	t_cd *cd;

	cd = ft_memalloc(sizeof(t_cd));
	init_struct(envar, cd);
	if (find_arg(envar, "HOME") == -1)
		envar = ft_setsenv(envar, "HOME", cd->cwd);
	if (!arg[1] || (ft_strncmp(arg[1], "~", 1) == 0 && envar[0]))
		envar = ft_home(arg, envar, cd);
	else if (arg[1] && (access(arg[1], F_OK)) == 0)
	{
		ft_gotodir(cd->tmp, arg);
		envar[cd->old] ? free(envar[cd->old]) : (0);
		envar[cd->old] = ft_strjoin("OLDPWD", cd->tmp2);
		cd->fr = envar[cd->pwd];
		envar[cd->pwd] = ft_strjoin("PWD=", cd->cwd);
	}
	else if (access(arg[1], F_OK) == -1 && envar[0])
		(ft_strcmp(arg[1], "-") == 0) ? ft_printlast(envar) :
			ft_printf("%s %s\n", FILE, arg[1]);
	else if (access(arg[1], R_OK) == -1 && envar[0])
		ft_printf("%s %s\n", DEN, arg[1]);
	free_struct(cd, arg);
	return (envar);
}
