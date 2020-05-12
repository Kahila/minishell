/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <akalombo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 14:25:26 by akalombo          #+#    #+#             */
/*   Updated: 2020/05/12 02:06:09 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "stdio.h"
/**
 * @author adonis kahila
 * @version 1.0
 * the following file works with process and execve
 */

int built_ins(char *str)
{
    if (ft_strcmp("cd", str) != 0 || ft_strcmp("echo", str) != 0)
        return (-1);
    return (0);
}

/**
 * @param  double pointer of type char
 * @return  the function returns antager
 */
void checkComand(char **envp)
{
    pid_t child;
    char **command;
    char *lineptr = NULL;
    char *c;
    size_t status;

    while (1)
    {
        ft_putstr("$ ");
        if (getline(&lineptr, &status, stdin) == -1)
            break;
        if (ft_strlen(lineptr) != 1)
        {
            c = lineptr;
            lineptr = ft_strtrim(lineptr);
            free(c);
            command = ft_strsplit(lineptr, ' '); 
        }
        child = fork();
        process(child, command, envp, status, lineptr);
        status = 0;
        if (ft_strlen(lineptr) > 1 && built_ins(command[0]) == -1)
        {
            while (command[status])
                free(command[status++]);
            free(command);
        }
    }
    ft_putchar('\n');
    free(lineptr);
    exit(status);
}

/**
 * 
 * the method creates a process and makes the parent process to wait for the child process to finish executing 
 * 
 * @param child value of time pid_t
 * @return the method returns void
 */

void process(pid_t child, char **command, char **envp, int status, char *ptr)
{
    if (child == 0) // No error checking; too close to being not a "snippet"
    {
        if (ft_strcmp("exit", ptr) == 0)
        {
            kill(child, SIGKILL); //killing the process on exit
            exit(0);
        }
        if (execve(command[0], command, envp) && echo_(command, ptr) == -1 && ft_strlen(ptr) != 1)
        {
            if (ch_dir(command) == -1)
            {
                perror("execve");
                exit(EXIT_FAILURE);
            }
        }
    }
    if (child > 0) // Successful forks return positive process id's the parent
        wait(&status);
}

void           ft_free(char ***command, char *lineptr)
{
    int status;

    status = 0;
    if (ft_strlen(lineptr) > 1)
    {
        while (*command[status])
            free(*command[status++]);
        free(*command);
    }

}
