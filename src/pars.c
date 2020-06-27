/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <akalombo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 14:25:26 by akalombo          #+#    #+#             */
/*   Updated: 2020/06/27 06:11:32 by ado              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static char *read_line()
{
    char    *line;

    line = NULL;
    get_next_line(0, &line);
    return (line);
}

char *rm_(char *str)
{
    char str1[10000];
    int i;
    int found;
    int j = 0;

    i = 0;
    found = 0;
    while (str[i])
    {
        while (str[i] == ' ' || str[i] =='\t')
        {
            i++;
            found = 1;
        }
        if (found == 1)
        {
            found = 0;
            str1[j] = ' ';
            j++;
        }
        str1[j] = str[i];
        i++;
        j++;
    }
    str1[j] = '\0';
    return (ft_strdup(str1));
}

size_t	crete_process(pid_t child, char **command, char *lineptr, char *c, char **envp)
{
    size_t	status;
    char *ptr;
    status = 0;
    while(1)
    {
        ft_putstr("\033[0;32m$>\033[0;37m ");
        if (lineptr)
            free(lineptr);
        ptr = read_line();
        lineptr = rm_(ptr);
        if (ptr)
            free(ptr);
        if ( lineptr == NULL)
            break;
        if (check_(lineptr) == -1)
        {
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
    }
    return (status);
}

void	checkComand(char **envp)
{
    pid_t	child;
    char	**command;
    char	*lineptr;
    char	*c;
    size_t	status;

    c = NULL;
    command = NULL;
    child = 0;
    lineptr = NULL;
    status = crete_process(child, command, lineptr, c, envp);
    ft_putchar('\n');
    if (lineptr)
        free(lineptr);
    exit(status);
}

void	process(pid_t child, char **command, char **envp, int status, char *ptr)
{
    if (child == 0)
    {
        if (ft_strcmp("exit", ptr) == 0)
        {
            kill(child, SIGKILL);
            exit(0);
        }
        final_path(command, envp);
        if (echo_(command, ptr) == -1 && ft_strlen(ptr) != 1)
        {
            if (ch_dir(command) == -1 && call_env(ptr) == -1 && env_(command[0]) == -1 && unset(ptr) == -1)
            {
                if (execve(command[0], command, envp)  == -1 && execve(g_path_, command, envp) == -1)
                {
                    ft_putstr("\033[0;31mminishell: command not found: ");
                    ft_putstr(ptr);
                    ft_putstr(".\033[0;37m");
                    ft_putchar('\n');
                    exit(EXIT_FAILURE);
                }
            }
        }
        if (ft_strlen(g_path_) > 1)
            free(g_path_);
    }
    if (child > 0)
        wait(&status);
}

void	ft_free(char ***command, char *lineptr)
{
    int	status;

    status = 0;
    if (ft_strlen(lineptr) > 1)
    {
        while (*command[status])
            free(*command[status++]);
        free(*command);
    }
}
