#include "minishell.h"

char **ft_dup_builtin(char **envar)
{
	int		i;
	char	**tmp;

	i = 0;
	if (!(tmp = (char **)malloc(sizeof(char *) * (g_len + 2))))
		return (NULL);
	while (envar[i])
	{
		tmp[i] = ft_strdup(envar[i]);
		i++;
	}
	envar ? free_tab(envar) : (0);
	return (tmp);
}

char **ft_setsenv(char **envar, char *arg1, char *arg2)
{
	int i;

	i = 0;
	while (ft_strncmp(envar[i], arg1, ft_strlen(arg1)) && i < g_len - 1)
		i++;
	if ((i + 1) == g_len)
	{
		envar = ft_dup_builtin(envar);
		envar[i + 1] = ft_strdup(arg1);
		envar[i + 1] = ft_strcat(envar[i + 1], "=");
		envar[i + 1] = ft_strcat(envar[i + 1], arg2);
		free(arg1);
		free(arg2);
		return (envar);
	}
	return (envar);
}

char	**ft_seteqenv(char **envar, char *arg1)
{
	int i;

	i = 0;
	while (ft_strncmp(envar[i], arg1, ft_strlen(arg1)) && i < g_len - 1)
		i++;
	if ((i + 1) == g_len)
	{
		envar = ft_dup_builtin(envar);
		envar[i + 1] = ft_strdup(arg1);
		(!ft_strchr(arg1, '=')) ? envar[i + 1] = ft_strcat(envar[i + 1],  "=") : NULL;
		ft_strdel(&arg1);
	}
	return (envar);
}

char  **ft_builtin(char **arg, char **envar)
{
	int j;

	if (!ft_strcmp(arg[0], "setenv"))
	{
		if (ft_checkarg(arg) != 0)
			(arg[2]) ? (envar = ft_setsenv(envar, arg[1], arg[2])) :
			(envar = ft_seteqenv(envar, arg[1]));
		free(arg[0]);
	}
	if (ft_strcmp(arg[0], "env") == 0)
	{
		ft_envdisplay(envar);
		free_envar(arg);
	}
	if (!ft_strncmp(arg[0], "unsetenv", ft_strlen("unsetenv")))
	{
		j = 1;
		if (ft_compare(envar, arg[j]) != -1)
		{
			while (arg[j])
			{
				envar = ft_unsetenv(envar, arg[j]);
				free_envar(arg);
				j++;
			}
		}
	}
	arg ? free(arg) : (0);
	return (envar);
}
