/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <akalombo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 14:25:26 by akalombo          #+#    #+#             */
/*   Updated: 2020/05/18 14:30:00 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	built_ins(char *str)
{
	if (ft_strcmp("cd", str) != 0 || ft_strcmp("echo", str) != 0)
		return (-1);
	else if (ft_strcmp("setenv", str) != 0 || ft_strcmp("env", str) != 0)
		return (-1);
	return (0);
}

int	check_(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > 32)
			return (-1);
		i++;
	}
	return (0);
}

int	env_(char *str)
{
	int		i;
	extern char	**environ;

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

int	len_check(char *str)
{
	size_t	i = 0;

	while (str[i] == ' ' || str[i] == '\t')
		i++;
	i++;
	if (i == ft_strlen(str))
		return (0);
	return (-1);
}

static char *read_line()
{
     char    *line;

     line = NULL;
     get_next_line(0, &line);
     return (line);
}

size_t	crete_process(pid_t child, char **command, char *lineptr, char *c, char **envp)
{
	size_t	status;

	status = 0;
	while(1)
	{
		ft_putstr("$> ");
        if (lineptr)
            free(lineptr);
        lineptr = read_line();
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
		if (g_path_ != NULL)
			free(g_path_);
		final_path(command, envp);
		if (echo_(command, ptr) == -1 && ft_strlen(ptr) != 1)
		{
			if (ch_dir(command) == -1 && call_env(ptr) == -1 && env_(command[0]) == -1 && unset(ptr) == -1)
			{
				if (execve(command[0], command, envp)  == -1 && execve(g_path_, command, envp) == -1)
				{
					ft_putstr("minishell: command not found: ");
					ft_putstr(ptr);
					ft_putchar('\n');
					exit(EXIT_FAILURE);
				}
			}
		}
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
