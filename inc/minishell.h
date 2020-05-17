/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <akalombo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 03:06:19 by akalombo          #+#    #+#             */
/*   Updated: 2020/05/17 10:52:41 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "libft/libft.h"
#include "stdlib.h"
#include "unistd.h"
#include "fcntl.h"
#include "sys/types.h"
#include "sys/uio.h"
#include "dirent.h"
#include "sys/stat.h"
#include "sys/wait.h"
#include "signal.h"
#include "stdio.h"

char                    g_path[100];
char                    **g_env;
char                    **g_set;

int                     unset(char *str);
char                    *get_path();
int                     final_path(char **c, char **d);
int                     ft_unsetenv(const char *name);
int                     compar(char *str, char *str1);
char                    **ft_realloc(size_t size);
int                     ft_setenv(const char *name, const char *value, int overwrite);
int                     call_env(char *str);
void                    set_env(char *var);
int                     free_(char **);
int                     init_env();
int                     ft_env(char *cmd, char **);
void                    ascii();
void                    run(char *argv);
void                    checkComand(char **envp);
void                    process(pid_t child, char **command, char **envp, int status, char *ptr);
int                     echo_(char **strs, char *ptr);
int                     ch_dir(char **strs);
char                    *g_path_;
void                    ft_free(char ***command, char *lineptr);

#endif
