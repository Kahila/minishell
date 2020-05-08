/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <akalombo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 03:02:07 by akalombo          #+#    #+#             */
/*   Updated: 2020/04/15 05:00:06 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include <curses.h>
#include "minishell.h"

void ascii(char *project){
    char *asc = ("\t\t\t\t\t                                  ___====-_  _-====___\n\
    \t\t\t\t\t                            _--^^^#####//      \\\\#####^^^--_\n\
    \t\t\t\t\t                         _-^##########// (    ) \\\\##########^-_\n\
    \t\t\t\t\t                        -############//  |\\^^/|  \\\\############-\n\
    \t\t\t\t\t                      _/############//   (@::@)   \\\\############\\_ \n\
    \t\t\t\t\t                     /#############((     \\\\//     ))#############\\ \n\
    \t\t\t\t\t                    -###############\\\\    (oo)    //###############-\n\
    \t\t\t\t\t                   -#################\\\\  / VV \\  //#################-\n\
    \t\t\t\t\t                  -###################\\\\/      \\//###################-\n\
    \t\t\t\t\t                 _#/|##########/\\######(   /\\   )######/\\##########|\\#_\n\
    \t\t\t\t\t                 |/ |#/\\#/\\#/\\/  \\#/\\##\\  |  |  /##/\\#/  \\/\\#/\\#/\\#| \\|\n\
    \t\t\t\t\t                 `  |/  V  V  `   V  \\#\\| |  | |/#/  V   '  V  V  \\|  '\n\
    \t\t\t\t\t                    `   `  `      `   / | |  | | \\   '      '  '   '\n\
    \t\t\t\t\t                                     (  | |  | |  )\n\
    \t\t\t\t\t                                    __\\ | |  | | /__\n\
    \t\t\t\t\t                            (####### |MINISHELL| #######)\n\n\n\n");

    ft_putstr(asc);
}