/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <akalombo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 03:06:19 by akalombo          #+#    #+#             */
/*   Updated: 2020/04/16 11:54:38 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "libft.h"
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

#endif
