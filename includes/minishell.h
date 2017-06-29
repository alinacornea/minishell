#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include "libft.h"
#include <sys/stat.h>
# include <limits.h>
# include <sys/wait.h>


int g_len;

char **ft_execute(char **arg, char **envar);
char **ft_builtin(char **arg, char **envar);
void ft_forkexe(char **arg, char **envar);
char	**ft_command(char **envar);
int		ft_strrlen(char **tab);
int ft_checkarg(char **arg);
char **ft_cd(char **arg, char **envar);
int ft_getbuiltin(char **arg);
char *get_param(char *str);
char **ft_setsenv(char **envar, char *arg1, char *arg2);
char		**ft_unsetenv(char **envar, char *param);
int ft_compare(char **envar, char *path);
char **ft_parse_echo(char **arg, char **envar);
void free_tab(char **tab);
void free_envar(char **envar);
int find_arg(char **envar, char *str);


#endif
