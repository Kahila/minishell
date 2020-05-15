/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <akalombo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 03:06:19 by akalombo          #+#    #+#             */
/*   Updated: 2020/05/15 18:07:39 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "libft/libft.h"
#include "stdlib.h" //malloc, free, exit
#include "unistd.h" //access, close, getcwd, chdir, fork, execve
#include "fcntl.h" //open
#include "sys/types.h"
#include "sys/uio.h"
#include "dirent.h" //opendir, readdir, closedir
#include "sys/stat.h" //stat, lstat, fstat
#include "sys/wait.h" //wait, waitpid, wait3, wait4
#include "signal.h" //signal, kill

char                    g_path[100];
char                    **g_env;
char                    **g_set;
 int      compar(char *str, char *str1);
char                    **ft_realloc(size_t size);
int                     ft_setenv(const char *name, const char *value, int overwrite);
int                     call_env(char *str);
void                    set_env(char *var);
int                     free_(char **);
int                     init_env();
int                     ft_env(char *cmd, char **);
void                    ascii(char *project);
void                    run(char *argv);
void                    checkComand(char **envp);
void                    process(pid_t child, char **command, char **envp, int status, char *ptr);
int                     echo_(char **strs, char *ptr);
int                     ch_dir(char **strs);
void                    ft_free(char ***command, char *lineptr);

#endif
