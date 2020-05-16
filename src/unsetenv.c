/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <akalombo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 19:10:00 by akalombo          #+#    #+#             */
/*   Updated: 2020/05/16 04:47:49 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "stdio.h"

int _count()
{
    int i;
    extern char **environ;

    i = 0;
    while (environ[i])
        i++;
    return (i);
}

//method that will be used for freeing the memory of the string unseted
void remove_(int index)
{
    char **tmp;
    extern char **environ;
    int i;
    int j;

    tmp = environ;
    i = 0;
    j = 0;
    printf("----%s\n", environ[_count()]);
    //free(environ[_count()]);
    free(environ[_count() - 1]);
    while (tmp[j])
    {
        if (j == index)
        {
            j++;
            index = -1;
            //free(environ[i])
            continue;
        }
        free(environ[i]);
        environ[i] = ft_strdup(tmp[j]);
        i++;
        j++;
    }

    //printf("--- %s\n", environ[j - 1]);
    //free(environ[j - 1]);
    environ[i] = NULL;
    //free_(tmp);
    return;
}


int ft_unsetenv(const char *name)
{
    extern char **environ;
    char **tmp;
    int i;

    i = 0;
    while (environ[i])
    {
        ///printf("== %i\n",compar(environ[i], (char *)name) );
        //free(environ[i]);
        if (compar(environ[i], (char *)name) == 0)
        {
            //environ[i] = "________";
            remove_(i);
            break;
        }
        i++;
    }
    return (0);
}

int unset(char *str)
{
    char **tmp;

    tmp = ft_strsplit(str, ' ');
    if (ft_strcmp(tmp[0], "unsetenv") == 0)
    {
        if (tmp[1])
            ft_unsetenv(tmp[1]);
        free_(tmp);
        return (0);
    }
    return (-1);
}
