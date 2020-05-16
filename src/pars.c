/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <akalombo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 14:25:26 by akalombo          #+#    #+#             */
/*   Updated: 2020/05/16 05:51:45 by akalombo         ###   ########.fr       */
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
    else if (ft_strcmp("setenv", str) != 0 || ft_strcmp("env", str) != 0)
        return (-1);
    return (0);
}

int env_(char *str)
{
    int i;
    extern char **environ;

    if (ft_strcmp(str, "env") == 0)
    {
        i = 0;
        while (environ[i])
        {
            ft_putendl(environ[i]);
            i++;
        }
        return (0);
    }
    return (-1);
}

int len_check(char *str)
{
    size_t i = 0;

    while (str[i] == ' ' || str[i] == '\t')
        i++;
    i++;
    if(i == ft_strlen(str))
        return (0);
    return (-1);
}

size_t crete_process(pid_t child, char **command, char *lineptr, char *c, char **envp)
{
    size_t status;

    status = 0;
    while(1)
    {
        ft_putstr("$> ");
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
    return (status);
}

/**
 * @param  double pointer of type char
 * @return  the function returns antager
 */
void checkComand(char **envp)
{
    pid_t child;
    char **command;
    char *lineptr;
    char *c;
    size_t status;

    lineptr = NULL;
    status = crete_process(child, command, lineptr, c, envp);
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
    if (child == 0)
    {
        if (ft_strcmp("exit", ptr) == 0)
        {
            kill(child, SIGKILL);
            exit(0);
        }
        if (execve(command[0], command, envp) && echo_(command, ptr) == -1 && ft_strlen(ptr) != 1)
        {
            if (ch_dir(command) == -1 && call_env(ptr) == -1 && env_(command[0]) == -1 && unset(ptr) == -1)
            {
                ft_putstr("minishell: command not found: ");
                ft_putstr(ptr);
                ft_putchar('\n');
                exit(EXIT_FAILURE);
            }
        }
    }
    if (child > 0)
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
