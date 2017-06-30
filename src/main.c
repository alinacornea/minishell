#include "minishell.h"

char	**ft_env(char **env)
{
	int		i;
	char	**tmp;

	i = 0;
	if (!(tmp = malloc(sizeof(char*) * ft_strrlen(env) + 1)))
		return (NULL);
	while (env[i])
	{
		tmp[i] = env[i];
		i++;
	}
	return (tmp);
}

int ft_getbuiltin(char **arg)
{
	if (ft_strcmp(arg[0], "echo") == 0)
		return (2);
	else if (ft_strcmp(arg[0], "cd") == 0)
		return (1);
	else if (ft_strcmp(arg[0], "env") == 0)
		return (0);
	else if (ft_strcmp(arg[0], "unsetenv") == 0)
		return (0);
	else if (ft_strcmp(arg[0], "setenv") == 0)
		return (0);
	return (-1);
}

char  **ft_execute(char **arg, char **envar)
{
	if (ft_strcmp(arg[0], "exit") == 0)
	{
		free_tab(arg);
		free(envar);
		exit(0);
	}
	else if (ft_getbuiltin(arg) == 0)
		envar = ft_builtin(arg, envar);
	else if(ft_getbuiltin(arg) == 1)
 		envar = ft_cd(arg, envar);
	else if (ft_getbuiltin(arg) == 2)
		envar = ft_parse_echo(arg, envar);
	else
		ft_forkexe(arg, envar);
	free_tab(arg);
	return (envar);
}

int	main(int argc, char **argv, char **env)
{
	int		nb;
	char	line[1024];
	char	**envar;
	char	**arg;

	if (argc && argv && env)
		envar = ft_env(env);
	while (1)
	{
			ft_putstr("<3 ");
			nb = read(0, line, 1024);
			if (nb == 0)
			{
				ft_putchar('\n');
				exit(0);
			}
			line[nb - 1] = '\0';
			arg = ft_strsplit(line, ' ');
			g_len = ft_strrlen(envar);
			if (arg[0] && env[0])
				envar = ft_execute(arg, envar);
	}
	return (0);
}
