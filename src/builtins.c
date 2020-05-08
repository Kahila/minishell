/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <akalombo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 23:49:46 by akalombo          #+#    #+#             */
/*   Updated: 2020/05/07 23:51:09 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "../minishell.h"

/**
 * @author akalombo
 * 
 * this file contains all the functions that concern builtins such as 'echo', 'cd'
*/

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
 * @param path
 * @return -1 if fail and 0 if success
 * the method will change directories
*/

int ch_dir(char **strs)
{
    // printf("%s\n", strs[0]);
    if (ft_strcmp("cd", strs[0]) == 0)
    {
        printf("this guy fina use cd\n");
        return (0);
    }
    return (-1);
}