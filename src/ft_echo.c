/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 16:24:28 by alcornea          #+#    #+#             */
/*   Updated: 2017/06/21 16:25:21 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		tab[i] ? free(tab[i]) : (0);
		tab[i] = NULL;
		i++;
	}
	tab ? free(tab) : (0);
}

void	free_envar(char **envar)
{
	int i;

	i = 0;
	while (envar[i])
	{
		envar[i] ? free(envar[i]) : (0);
		i++;
	}
}

int		ft_echoenv(char **arg, char **envar, int i)
{
	int		value;
	char	*sign;

	sign = NULL;
	if (arg[i][0] == '$')
		sign = ft_strsub(arg[i], 1, ft_strlen(arg[i]));
	else
		sign = ft_strsub(arg[i], 2, ft_strlen(arg[i]) - 3);
	value = ft_compare(envar, sign);
	if (value != -1)
		ft_printf("%s\n", get_param(envar[value]));
	else
		ft_printf("%s: Undefined variable.\n", sign);
	// free_tab(arg);
	sign ? ft_strdel(&sign) : (0);
	return (0);
}

char	**ft_parse_echo(char **arg, char **envar)
{
	int i;
	int f;
	int k;

	i = 0;
	while (arg[++i])
	{
		k = 0;
		while (arg[i][k])
		{
			if (arg[i][k] == '$' || (arg[i][k] == '"' && arg[i][k + 1] == '$'))
			{
				f = ft_echoenv(arg, envar, i);
				break ;
			}
			else if (arg[i][k] == '"' || arg[i][k] == '\\')
				k++;
			ft_putchar(arg[i][k]);
			k++;
		}
		f ? ft_putchar(' ') : (0);
	}
	f ? ft_putchar('\n') : (0);
	free_tab(arg);
	return (envar);
}
