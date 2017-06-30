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
	return (tmp);
}

char **ft_setsenv(char **envar, char *arg1, char *arg2)
{
	int i;

	i = 0;
	while ((ft_strncmp(envar[i], arg1, ft_strlen(arg1)) != 0) && i < g_len - 1)
		i++;
	if ((i + 1) == g_len)
	{
		envar = ft_dup_builtin(envar);
		envar[i + 1] = ft_strdup(arg1);
		envar[i + 1] = ft_strcat(envar[i + 1], "=");
		envar[i + 1] = ft_strcat(envar[i + 1], arg2);
		ft_strdel(&arg1);
		return (envar);
	}

	return (envar);
}

char	**ft_seteqenv(char **envar, char *arg1) //set equal
{
	int i = 0;

	if (arg1)
	{
		while ((ft_strncmp(envar[i], arg1, ft_strlen(arg1)) != 0) && i < g_len - 1)
			i++;
		if ((i + 1) == g_len)
		{
			envar = ft_dup_builtin(envar);
			envar[i + 1] = ft_strdup(arg1);
			(!ft_strchr(arg1, '=')) ? envar[i + 1] = ft_strcat(envar[i + 1],  "=") : NULL;
		}
		ft_strdel(&arg1);
	}
	else
	{
		while (envar[i])
		{
			ft_printf("%s\n", envar[i]);
			i++;
		}
	}
	return (envar);
}

void ft_envdisplay(char **envar)
{
	int i;

	i = 0;
	while (envar[i] && i < g_len)
	{
		printf("%s\n", envar[i]);
		i++;
	}
}

char  **ft_builtin(char **arg, char **envar)
{
	int j;

	if ((ft_strcmp(arg[0], "setenv") == 0))
	{
		if (ft_checkarg(arg) != 0)
			(arg[2]) ? (envar = ft_setsenv(envar, arg[1], arg[2])) : (envar = ft_seteqenv(envar, arg[1]));
	}
	if (ft_strcmp(arg[0], "env") == 0)
		ft_envdisplay(envar);
	if (ft_strcmp(arg[0], "unsetenv") == 0)
	{
		j = 1;
		if (ft_compare(envar, arg[j]) != -1)
		{
			while (arg[j])
			{
				envar = ft_unsetenv(envar, arg[j]);
				j++;
			}
		}
	}
	return (envar);
}
