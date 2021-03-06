/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <akalombo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 23:49:46 by akalombo          #+#    #+#             */
/*   Updated: 2020/05/22 21:31:48 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void print_str(char *str)
{
    int i;
    int j;

    i = 5;
    while (str[i])
    {
        if (str[i] == '\"')
            while (str[i])
            {
                if (str[i] != '\"')
                    ft_putchar(str[i]);
                i++;
                if (str[i] == '\"')
                    break;
            }
        if (str[i] != ' ' && j == 1 && str[i] != '\"')
        {
            j = 0;
            ft_putchar(' ');
        }
        if (str[i] != ' ' && str[i] != '\"')
            ft_putchar(str[i]);
        else if (str[i] == ' ')
            j = 1;
        i++;
    }
}

int  echo_env(char *str)
{
    extern char **environ;
    char **tmp;
    char **split_;
    char *joined;
    int i;

    i = 0;
    split_ = ft_strsplit(str, ' ');
    if (split_[1] && split_[1][0] == '$')
    {
    while (environ[i])
    {
        tmp = ft_strsplit(environ[i], '=');
        joined = ft_strjoin("$", tmp[0]);
        if (ft_strcmp(joined, split_[1]) == 0)
        {
            ft_putendl(tmp[1]);
            free_(tmp);
            free(joined);
            free_(split_);
            return (0);
        }
        free_(tmp);
        free(joined);
        i++;
    }
    free_(split_);
    return (0);
    }
    free_(split_);
    return (-1);
}

int echo_(char **strs, char *ptr)
{
    if (ft_strcmp(strs[0], "echo") == 0)
    {
        if (echo_env(ptr) == -1)
        {
        print_str(ptr);
        ft_putchar('\n');
        exit(0);
        //return (0);
        }
        exit (0);
    }
    return (-1);
}

void count_fall_backs()
{
    int i;
    int found;
    char path[100];
    char new[1000];

    getcwd(path, 100);
    i = found = 0;
    while (path[i])
    {
        new[i] = path[i];
        i++;
        if (path[i] == '/')
            found++;
        if (found == 2)
            break;
    }
    new[i] = '\0';
    chdir(new);
}

int ch_dir(char **strs)
{
    if (ft_strcmp("cd", strs[0]) == 0)
    {
        if (!strs[1] || ft_strcmp("-", strs[1]) != 0)
            getcwd(g_path, 100);
        if (!strs[1] || ft_strcmp("~", strs[1]) == 0)
        {
            count_fall_backs();
            return (0);
        }
        if (ft_strcmp("-", strs[1]) == 0)
        {
            chdir(g_path);
            return (0);
        }
        if (chdir(strs[1]) == -1 && strs[1])
            return (-1);
        return (0);
    }
    return (-1);
}
