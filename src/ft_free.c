/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 16:24:28 by alcornea          #+#    #+#             */
/*   Updated: 2017/06/21 16:25:21 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_struct(t_cd *cd, char **arg)
{
	cd->pwd = 0;
	cd->old = 0;
	cd->fr ? ft_strdel(&cd->fr) : (0);
	free(cd->home);
	free(cd);
	free_tab(arg);
}

void	free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		tab[i] ? free(tab[i]) : (0);
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
