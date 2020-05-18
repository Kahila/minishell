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

NAME= minishell

IDIR = ./inc/
INCS = libft.h	\
	   minishell.h
INCC = $(addprefix $(IDIR), $(INCS))

LDIR = ./inc/libft
LIBS = -lft

SDIR = ./src/
SRCS = ascii.c cd_echo_.c ft_path_man.c ft_setenv.c ft_unsetenv.c minishell.c pars.c

SRCC = $(addprefix $(SDIR),$(SRCS))

ODIR = ./objs/
OBJS = $(SRCS:.c=.o)
OBCC = $(addprefix $(ODIR),$(OBJS))

FLAG = -g -Wall -Werror -Wextra

$(NAME): $(OBCC)
	make -C ./inc/libft/
	gcc $(FLAG) $(OBCC) -L$(LDIR) $(LIBS) -o $(NAME)

$(ODIR)%.o: $(SDIR)%.c
	@mkdir -p $(ODIR)
	gcc $^ $(FLAG) -c -o $@ -I$(IDIR)

all: $(NAME)

clean:
	make -C inc/libft clean
	rm -f $(OBJS)

fclean:	clean
	make -C inc/libft fclean
	rm -f $(NAME)

re : fclean all
