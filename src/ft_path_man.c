/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_man.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <akalombo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 08:55:57 by akalombo          #+#    #+#             */
/*   Updated: 2020/05/17 12:05:14 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char *get_path(char **environ)
{
    char *found;
    char **paths;
    int i;

    paths = NULL;
    i = 0;
    while (environ[i])
    {
        if (compar(environ[i], "PATH") == 0)
            found = ft_strdup(environ[i]);
        i++;
    }
    if (found)
    {
        paths = ft_strsplit(found, ':');
        i = 0;
        free(found);
        while (paths[i])
        {
            if (ft_strcmp("/bin", paths[i]) == 0 || ft_strcmp("PATH=/bin", paths[i]) == 0)
                found = ft_strdup(paths[++i]);
            i++;
        }
        free_(paths);
        return (found);
    }
    return (NULL);
}

int final_path(char **command, char **envp)
{
    // char *path;
    char *s = NULL;

    g_path_ = get_path(envp);
    if (g_path_)
    {
        s = ft_strjoin(g_path_, "/");
        free(g_path_);
        g_path_ = ft_strjoin(s, command[0]);
        free(s);
        return (0);
    }
    return (-1);
}
