/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <akalombo@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 20:24:37 by akalombo          #+#    #+#             */
/*   Updated: 2020/05/29 20:27:41 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "stdio.h"

int main ()
{
    pid_t child;
    int i = 1;

    child = fork();
    if (child == 0)
        printf("child %i\n", i++);
    else
        printf("parents %i\n", i++);
    return (0);
}
