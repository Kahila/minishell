/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <akalombo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 23:58:37 by akalombo          #+#    #+#             */
/*   Updated: 2020/05/15 01:12:21 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

extern char **environ;


int count()
{
    int i = 0;
    while (environ[i])
        i++;

    return (++i);
}

int main(int argc, char **argv, char **env)
{
    //free(environ);
    char **new;

    printf("the value of count is = %i\n", count());
    new = (char **)malloc(sizeof(char *)*(count() + 1));

    int i = 0;
    //environ[0] = "ADONIS";
    while (environ[i])
    {
        printf("environ - %i - %s\n",i, environ[i]);
        //printf("env --- %s\n", env[i]);
        new[i] = strdup(environ[i]);
        i++;
    }
    new[i] = NULL;
    i = 0;
    environ = (char **)malloc(sizeof(char*) *(count() + 2));
    while (new[i])
    {
        environ[i] = new[i];
        free(new[i]);
        i++;
    }
    environ[i] = strdup(argv[0]);
    environ[i+1] = NULL;

    i = 0;
    while (environ[i])
    {
        printf("--------%s\n", environ[i]);
        i++;
    }
    while (1)
    {
    }
    return (0);
}*/
