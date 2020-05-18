/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <akalombo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 02:49:45 by akalombo          #+#    #+#             */
/*   Updated: 2020/05/18 23:25:18 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int main(int argc, char **argv, char *envp[]){
    
    init_env();
    if (argc > 0 && argv[0] != NULL){
      checkComand(envp);
    }
    if (g_set)
        free(g_set);
    return (0);
}
