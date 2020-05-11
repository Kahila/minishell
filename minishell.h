/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <akalombo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 03:06:19 by akalombo          #+#    #+#             */
/*   Updated: 2020/05/12 01:25:43 by akalombo         ###   ########.fr       */
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

void                    ascii(char *project);
void                    run(char *argv);
void                     checkComand(char **envp);
void                    process(pid_t child, char **command, char **envp, int status, char *ptr);
int                     echo_(char **strs, char *ptr);
int                     ch_dir(char **strs);
void                    ft_free(char ***command, char *lineptr);

#endif
