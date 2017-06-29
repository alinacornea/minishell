#include "minishell.h"

int ft_strrlen(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void free_tab(char **tab)
{
	int i = 0;

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

	while(envar[i] && i < g_len)
	{
		envar[i] ? free(envar[i]) : (0);
		i++;
	}
}

int ft_checkarg(char **arg)
{
	int i;
	int j;
	int flag;

	i = 0;
	flag = 0;
	while (arg[i])
	{
		if (ft_strrlen(arg) > 3)
		{
			ft_printf("setenv: Too many arguments.\n");
			flag = 1;
			break;
		}
		else if (ft_isdigit(arg[i][0]))
			flag = 2;
		j = 0;
		while (arg[i][j])
		{
			if(!ft_isalnum(arg[i][j]))
				flag = 3;
			j++;
		}
		i++;
	}
	if (flag == 2 && ft_strrlen(arg) <= 3)
		ft_printf("setenv: Variable name must begin with a letter.\n");
	else if (flag == 3 && ft_strrlen(arg) <= 3)
		ft_printf("setenv: Variable name must contain alphanumeric characters.\n");
	return ((flag > 0) ? 0 : 1);
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
