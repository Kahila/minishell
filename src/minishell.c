/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <akalombo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 02:49:45 by akalombo          #+#    #+#             */
/*   Updated: 2020/05/16 13:35:21 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include "stdio.h"

int main(int argc, char **argv, char *envp[]){
    
    init_env();
    if (argc > 0 && argv[0] != NULL){
    //  ascii("MINISHELL");
      //run_execve(argv);
      checkComand(envp);
    }
    free(g_set);
    return (0);
}
