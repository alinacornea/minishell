#include "minishell.h"

void free_tab(char **tab)
{
	int i = -1;

	while(tab[i])
	{
		tab[i] ? free(tab[i]) : (0);
		i++;
	}
	tab ? free(tab) : (0);
}

void free_envar(char **envar)
{
	int i = 0;

	while(envar[i])
	{
		envar[i] ? free(envar[i]) : (0);
		i++;
	}
}

void ft_echoenv(char *arg, char **envar)
{
		int value = 0;

		value = ft_compare(envar, arg);
		if (value != -1)
			ft_printf("%s\n", get_param(envar[value]));
		else
			ft_printf("%s: Undefined variable.\n", arg);
}

char **ft_parse_echo(char **arg, char **envar)
{
	int i;
	int flag;
	char *sign = NULL;
	int k;

	i = 1;
	flag = 1;
	while (arg[i])
	{
		k = 0;
		while (arg[i][k])
		{
			if (arg[i][k] == '$' || (arg[i][k] == '"' && arg[i][k + 1] == '$'))
			{
				((arg[i][k] == '$') ? (sign = ft_strsub(arg[i], 1, ft_strlen(arg[i]))) : (sign = ft_strsub(arg[i], 2, ft_strlen(arg[i]) - 3)));
				ft_echoenv(sign, envar);
				flag = 0;
				break;
			}
			else if (arg[i][k] == '"' || arg[i][k] == '\\')
				k++;
			ft_putchar(arg[i][k]);
			k++;
		}
		flag ? ft_putchar(' ') : (0);
		i++;
	}
	flag ? ft_putchar('\n') : (0);
	return (envar);
}
