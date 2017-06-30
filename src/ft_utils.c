#include "minishell.h"

//
// char	*ft_strjoincl(char *s1, char *s2, int free_both)
// {
// 	char	*new;
//
// 	if (!(new = ft_strjoin(s1, s2)))
// 		return (NULL);
// 	free(s1);
// 	s1 = NULL;
// 	if (free_both)
// 	{
// 		free(s2);
// 		s2 = NULL;
// 	}
// 	return (new);
// }
// char	*ft_strjoinchcl(char *s1, char c)
// {
// 	char	*new;
//
// 	if (!(new = ft_strjoinch(s1, c)))
// 		return (NULL);
// 	free(s1);
// 	s1 = NULL;
// 	return (new);
// }
//
//
// char	*ft_strjoinch(char const *s1, char c)
// {
// 	char	*new_str;
// 	size_t	i;
// 	size_t	s1_len;
//
// 	if (!s1 || !c)
// 		return (NULL);
// 	s1_len = ft_strlen(s1);
// 	new_str = ft_strnew(s1_len + 1);
// 	if (!new_str)
// 		return (NULL);
// 	i = -1;
// 	while (++i < s1_len)
// 		*(new_str + i) = *(s1 + i);
// 	*(new_str + i) = c;
// 	return (new_str);
// }


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
		ft_printf("%s\n", envar[i]);
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
