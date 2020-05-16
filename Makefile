#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: akalombo <akalombo@42.fr>                  +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2020/05/07 22:08:40 by akalombo          #+#    #+#             *#
#*   Updated: 2020/05/07 22:09:05 by akalombo         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME= minishell.a

CC= gcc

SRC= minishell.c ascii.c src/pars.c

OBJ= minishell.0 ascii.o pars.once

FLAGS= -Wextra -Werror -Wall

all: $(NAME)

$(NAME):
	$(CC) -c $(FLAGS) $(SRC)
	ar rc $(NAME) &(OBJ)
	ranlib $(NAME)
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all