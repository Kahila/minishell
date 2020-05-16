/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <akalombo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 23:56:42 by akalombo          #+#    #+#             */
/*   Updated: 2020/05/16 07:54:10 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

//method that will init the environ
int  init_env()
{
    int i = 0;
    extern char **environ;
    char **tmp = environ;

    while(tmp[i])
    {
        if (compar(tmp[i],"XPC_SERVICE_NAME") == 0)
        {
           environ[i] = tmp[i];
            i++;
        }
        environ[i] = ft_strdup(tmp[i]);
        i++;
    }
    g_set = environ;
    return (i);
}

//method for comaring the name
int      compar(char *str, char *str1)
{
    int i = 0;
    int j = 0;

    while(str[i] != '=')
    {
        if ((str[i] == str1[i]) && str1[i] != '\0')
            j++;
        else
            break;
        i++;
    }
    if (j == (ft_strlen(str1)))
        return (0);
    else
        return (-1);
}

//method that is going to return the index of the similar name
int replace_(char *str)
{
    int i = 0;
    extern char **environ;

    while (environ[i])
    {
        if (compar(environ[i], str) == 0)
            return(i);
        i++;
    }
    return (-1);
}

//method that is going to init the extern array for modification
int free_(char **strs)
{
    int i;

    i = 0;
    while (strs[i])
        free(strs[i++]);
    free(strs);
    return (0);
}

//method that is going to be used to split the string that will call ft_setenv
//and get the value of overwrite
int  call_env(char *str)
{
    char **args;
    char **new;
    extern char **environ;

    args = ft_strsplit(str, ' ');
    if(ft_strcmp(args[0], "setenv") == 0)
    {
        new = ft_strsplit(args[1], '=');
        ft_setenv(new[0],new[1], 0);
        free_(args);
        free_(new);
        return (0);
    }
    free_(args);
    return (-1);
}

//method that is used to get the amount of the env content
size_t count_()
{
    extern char **environ;
    int i = 0;

    while (environ[i])
        i++;

    return (i);
}

void ft_real(char **add, int index)
{
    extern char** environ;
    int i;

    i = count_();
    if (index == -1)
    {
        free(environ[i]);
        environ[i] = ft_strdup(*add);
    }
    else
    {
        free(environ[index]);
        environ[index] = ft_strdup(*add);
    }
    environ[i+1] = NULL;
}

//method that will copy the content to the env 
int ft_setenv(const char *name, const char *value, int overwrite)
{
    char *tmp = ft_strjoin(name, "=");
    char *new;
    new = ft_strjoin(tmp, value);
    if (value)
        ft_real(&new, replace_((char *)name));
    else
        ft_real(&tmp, replace_((char *)name));
    free(new);
    free(tmp);
    return (0);
}
