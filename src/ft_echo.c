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

int		ft_echoenv(char **arg, char **envar, int i)
{
	int		value;
	char	*sign;
	char	*param;

	sign = NULL;
	if (arg[i][0] == '$')
		sign = ft_strsub(arg[i], 1, ft_strlen(arg[i]));
	else
		sign = ft_strsub(arg[i], 2, ft_strlen(arg[i]) - 3);
	value = ft_compare(envar, sign);
	param = get_param(envar[value]);
	if (value != -1)
		ft_printf("%s\n", param);
	else
		ft_printf("%s: Undefined variable.\n", sign);
	param ? ft_strdel(&param) : (0);
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
