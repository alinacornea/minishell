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
	ft_strdel(&home);
	return (tmp);
}

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

void	ft_gotodir(char *tmp, char **arg)
{
	char *new;
	char *str;

	str = NULL;
	if (ft_strncmp(arg[1], "/", 1))
	{
		str = getcwd(tmp, 2048);
		new = ft_strcat(str, "/");
		new = ft_strcat(new, arg[1]);
		new = ft_strcat(new, "/");
	}
	else
		new = ft_strdup(arg[1]);
	chdir(new);
	new ? ft_strdel(&new) : (0);
}

char	**ft_home(char **arg, char **envar, t_cd *cd)
{
	char	*new;

	new = NULL;
	new = get_param(envar[find_arg(envar, "HOME")]);
	if (arg[1] && ft_strlen(arg[1]) > 1)
	{
		new = ft_setnew(new, arg);
		(access(new, F_OK) == -1) ? ft_printf("%s %s\n", FILE, new) : (0);
	}
	if (arg[1] && !ft_strncmp(arg[1], "-", 1))
		new = ft_printlast(envar, new, cd);
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
	if (!arg[1] || (!ft_strncmp(arg[1], "~", 1)) ||
		!ft_strncmp(arg[1], "-", 1))
		envar = ft_home(arg, envar, cd);
	else if (arg[1] && (!access(arg[1], F_OK)))
	{
		ft_gotodir(cd->tmp, arg);
		envar[cd->old] ? free(envar[cd->old]) : (0);
		envar[cd->old] = ft_strjoin("OLDPWD=", cd->param);
		cd->fr = envar[cd->pwd];
		envar[cd->pwd] = ft_strjoin("PWD=", cd->cwd);
	}
	else if (access(arg[1], F_OK) == -1 && envar[0])
		ft_printf("%s %s\n", FILE, arg[1]);
	else if (access(arg[1], R_OK) == -1 && envar[0])
		ft_printf("%s %s\n", DEN, arg[1]);
	free_struct(cd, arg);
	return (envar);
}
