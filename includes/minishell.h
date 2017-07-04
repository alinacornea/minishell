#ifndef MINISHELL_H
#define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <unistd.h>
# include "libft.h"
# include <sys/stat.h>
# include <limits.h>
# include <sys/wait.h>

# define ARGS "setenv: Too many arguments."
# define LETTER "setenv: Variable name must begin with a letter."
# define ALPHA "setenv: Variable name must contain alphanumeric characters."
# define NOT ": Command not found."
#	define CL "\e[1;1H\e[2J"
#	define FILE "cd: no such file or directory:"
# define RED "\033[31m"
# define RESET "\033[0m"

typedef	struct		s_exe
{
	char	**tab;
	int		i;
	pid_t	pid;
	int		w;
	char	*tmp;
}					t_exe;

typedef struct		s_cd
{
	int pwd;
	int old;
	char *param;
	char *cwd;
	char *tmp;
	char *fr;
	char *tmp2;
}								t_cd;

char **ft_execute(char **arg, char **envar);
char **ft_builtin(char **arg, char **envar);
char **ft_cd(char **arg, char **envar);
char **ft_parse_echo(char **arg, char **envar);
char **ft_setsenv(char **envar, char *arg1, char *arg2);
char **ft_unsetenv(char **envar, char *param);
char *get_param(char *str);
void ft_forkexe(char **arg, char **envar);
int ft_getbuiltin(char **arg);
int ft_compare(char **envar, char *path);
void free_tab(char **tab);
void free_envar(char **envar);
void free_arg(char **arg);
int find_arg(char **envar, char *str);
int	ft_strrlen(char **tab);
int ft_checkarg(char **arg);
void ft_gotodir(char *tmp, char **arg);
void ft_printlast(char **envar);
void ft_envdisplay(char **envar);

#endif
