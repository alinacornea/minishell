#include "minishell.h"

char		**ft_tabreallocless(char **envar, int j)
{
	char	**tmp;
	int		i;
	int		k;

	k = 0;
	i = 0;
	tmp = (char**)malloc(sizeof(char*) * ft_strllen(envar));
	while (i < ft_strllen(envar))
	{
		if (i == j)
			i++;
		if (envar[i] != NULL){
			tmp[k] = ft_strdup(envar[i]);
			envar[i] ? free(envar[i]) : (0);
		}
		else
			tmp[k] = NULL;
		i++;
		k++;
	}
	return (tmp);
}

char **ft_unsetenv(char **envar, char *param)
{
	int	i;
	int j;

	i = 0;
	param = ft_strjoin(param, "=");
	while (i < ft_strllen(envar))
	{
		if (!ft_strncmp(envar[i], param, ft_strlen(param)))
			j = i;
		i++;
	}
	envar = ft_tabreallocless(envar, j);
	free(param);
	return (envar);

}
