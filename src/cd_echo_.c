/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <akalombo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 23:49:46 by akalombo          #+#    #+#             */
/*   Updated: 2020/05/13 19:29:53 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "../minishell.h"

/**
 * @author akalombo
 * 
 * this file contains all the functions that concern builtins such as 'echo', 'cd' and exit
*/

//char g_path[100];
// int fg_found = 0;

/**
 * @param string to be manipulated
 * @return void
 * the method is going to manipulate the string while displaying it
*/

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

/**
 * @param comand
 * @return -1 if fail and 0 if success
 * the method will be used to echo out the string that is passed after the echo comand
*/

int echo_(char **strs, char *ptr)
{
    //char **split = ft_strsplit(str, ' ');
    if (ft_strcmp(strs[0], "echo") == 0)
    {
        int i = 0;
        print_str(ptr);
        ft_putchar('\n');
        return (0);
    }
    return (-1);
}

/**
 * @fn ch_dir
 * @param path
 * @return -1 if fail and 0 if success
 * the method will change directories to the provided path
 * if the path is not set then the function will cd to the home dir
*/

//helper method to the cd_dir .. will be used to handle the "cd ~" flag
void count_fall_backs()
{
    int i;
    int found;
    char path[100];
    char new[1000];

    getcwd(path, 100); //getting the path of the current dir for modification
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

//method that will handle the "cd -" flag for moving to previous path

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
            return (-1); //will cause the error to be handled as an unknown file or dir by execve
        return (0);
    }
    return (-1);
}
