#include "minishell.h"

char **ft_dup_builtin(char **envar)
{
	int		i;
	char	**tmp;
	char 	**tmp2;

	i = 0;
	tmp2 = envar;
	if (!(tmp = (char **)malloc(sizeof(char *) * (g_len + 2))))
		return (NULL);
	while (tmp2[i])
	{
		tmp[i] = ft_strdup(tmp2[i]);
		i++;
	}
	tmp2 ? free(envar) : (0);
	return (tmp);
}

char **ft_setsenv(char **envar, char *arg1, char *arg2)
{
	int i;

	i = 0;
	while ((ft_strncmp(envar[i], arg1, ft_strlen(arg1)) != 0) && i < g_len - 1)
		i++;
	while ((i + 1) == g_len)
	{
		envar = ft_dup_builtin(envar);
		envar[i + 1] = ft_strcat(arg1, "=");
		envar[i + 1] = ft_strcat(envar[i + 1], arg2);
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

void ft_envdisplay(char **arg, char **envar)
{
	int i;

	i = 1;
	while (envar[i] && i < g_len)
	{
		printf("%s\n", envar[i]);
		i++;
	}
	free_tab(arg);
}

char  **ft_builtin(char **arg, char **envar)
{
	if (ft_strcmp(arg[0], "setenv") == 0)
	{

		if (arg[2] && ft_checkarg(arg))
			envar = ft_setsenv(envar, arg[1], arg[2]);
		else
			envar = ft_seteqenv(envar, arg[1]);
		free_envar(envar);
	}
	if (ft_strcmp(arg[0], "unsetenv") == 0)
	{
		int j = 1;
		if (ft_compare(envar, arg[j]) != -1)
		{
			while (arg[j])
			{
				envar = ft_unsetenv(envar, arg[j]);
				free_envar(envar);
				free_tab(arg);
				j++;
			}
		}
	}
	if (ft_strcmp(arg[0], "env") == 0)
		ft_envdisplay(arg, envar);
	return (envar);
}
