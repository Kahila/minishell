/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <akalombo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 14:25:26 by akalombo          #+#    #+#             */
/*   Updated: 2020/04/30 03:07:53 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "stdio.h"
/**
 * @author adonis kahila
 * @version 1.0
 * the following file works with process and execve
*/

/**
 * @param  double pointer of type char
 * @return  the function returns antager
*/
int checkComand(char **envp)
{
    pid_t child;
    char **command;
    char *lineptr = NULL;
    size_t i;
    int status = 0;

    while (1)
    {
        ft_putstr("$ ");
        if (getline(&lineptr, &i, stdin) == -1)
            break;
        lineptr = ft_strtrim(lineptr);       /// must be freed
        command = ft_strsplit(lineptr, ' '); //must be freed
        child = fork();
        process(child, command, envp, status, lineptr);
    }
    ft_putchar('\n');
    free(lineptr);
    exit(status);
    return (0);
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
    if (strcmp(command[0], "exit") == 0) //if the command passed is equal to exit than the program will exit
        exit(0);
    else if (child == 0) // No error checking; too close to being not a "snippet"
    {
        printf("exec : |%s|\n", command[0]);
        if (execve(command[0], command, envp) && echo_(command, ptr) == -1)
        {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    }
    if (child > 0) // Successful forks return positive process id's the parent
        wait(&status);
}