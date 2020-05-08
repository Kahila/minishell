/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <akalombo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 02:49:45 by akalombo          #+#    #+#             */
/*   Updated: 2020/04/30 11:44:50 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "stdio.h"

int main(int argc, char **argv, char *envp[]){
    
    if (argc > 0 && argv[0] != NULL){
      ascii("MINISHELL");
      checkComand(envp);
    }
    return (0);
}