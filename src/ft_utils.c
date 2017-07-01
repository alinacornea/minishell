#include "minishell.h"

int ft_strrlen(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void ft_printlast(char **envar)
{
	int oldpwd;
	char *str;

	str = NULL;
	oldpwd = find_arg(envar, "OLDPWD");
	if (ft_strlen(envar[oldpwd]) > 26)
		str = ft_strsub(envar[oldpwd], 27, ft_strlen(envar[oldpwd]) - 27);
	str ? ft_printf("~%s\n",str) : ft_printf("~\n");
	str ? free(str) : (0);
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

int ft_checkarg(char **arg)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (arg[i])
	{
		if (ft_strrlen(arg) > 3)
		{
			ft_printf("%s\n", ARGS);
			flag = 1;
			break ;
		}
		else if (ft_isdigit(arg[i][0]) && ft_strrlen(arg) <= 3)
    {
			ft_printf("%s\n", LETTER);
      break ;
    }
		i++;
	}
	return (flag ? 0 : 1);
}
