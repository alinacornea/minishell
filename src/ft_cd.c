#include "minishell.h"

char	*ft_strjoincl(char *s1, char *s2, int free_both)
{
	char	*new;

	if (!(new = ft_strjoin(s1, s2)))
		return (NULL);
	free(s1);
	s1 = NULL;
	if (free_both)
	{
		free(s2);
		s2 = NULL;
	}
	return (new);
}

char *ft_setnew(char *str, char **arg)
{
	char *tmp;
	size_t i;
	size_t j;

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
	str = ft_strjoin(str, tmp);
	tmp ? free(tmp) : (0);
	return (str);
}

int find_arg(char **envar, char *str)
{
	int i;

	i = 0;
	while (envar[i] != NULL && str)
	{
		if (ft_strncmp(envar[i], str, ft_strlen(str)) == 0)
			return (i);
		i++;
	}
	return (-1);
}

void ft_gotodir(char *tmp, char **arg)
{
	char *new;

	if (ft_strcmp(arg[1], "/") != 0)
	{
		new = ft_strcat(getcwd(tmp, 2048), "/");
		new = ft_strcat(new, arg[1]);
		new = ft_strcat(new, "/");
	}
	else
		new = ft_strdup("/");
	chdir(new);
	new ? ft_strdel(&new) : (0);
}

char **ft_home(char *tmp, char **arg, char **envar)
{
	int pwd;
	char *new;

	new = get_param(envar[find_arg(envar, "HOME")]);
	if (ft_strlen (arg[1]) > 1)
		new = ft_setnew(new, arg);
	chdir(new);
	pwd = find_arg(envar, "PWD");
	if (pwd != -1)
	{
		envar[find_arg(envar, "OLDPWD")] = ft_strjoin("OLDPWD=",get_param(envar[pwd]));
		envar[pwd] = ft_strjoin("PWD=", getcwd(tmp, 2048));
	}
	new ? ft_strdel(&new) : (0);
	return (envar);
}

char	**ft_homedir(char *tmp, char **envar)
{
	int pwd;
	char *new;
	char *param;

	new = get_param(envar[find_arg(envar, "HOME")]);
	chdir(new);
	pwd = find_arg(envar, "PWD");
	if (pwd != -1)
	{
		param = get_param(envar[pwd]);
		envar[find_arg(envar, "OLDPWD")] = ft_strjoin("OLDPWD=", param);
		envar[pwd] = ft_strjoin("PWD=", getcwd(tmp, 2048));
		ft_strdel(&param);
	}
	new ? ft_strdel(&new) : (0);
	return (envar);
}

char **ft_cd(char **arg, char **envar)
{
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp2 = ft_strchr(envar[find_arg(envar, "PWD")], '=');
	if (find_arg(envar, "HOME") == -1)
		envar = ft_setsenv(envar, "HOME", getcwd(tmp, 2049));
	if (!arg[1])
		envar = ft_homedir(tmp, envar);
	else if(ft_strncmp(arg[1], "~", 1) == 0 && envar[0])
		envar = ft_home(tmp, arg, envar);
	else if (arg[1] && (access(arg[1], F_OK)) == 0)
	{
		ft_gotodir(tmp, arg);
		envar[find_arg(envar, "OLDPWD")] = ft_strjoin("OLDPWD", tmp2);
		envar[find_arg(envar, "PWD")] = ft_strjoin("PWD=", getcwd(tmp, 2048));
	}
	else if (access(arg[1], F_OK) == -1 && envar[0])
		(ft_strcmp(arg[1], "-") == 0) ? ft_printlast(envar) : ft_printf("cd: no such file or directory: %s\n", arg[1]);
	free_tab(arg);
	return (envar);
}
