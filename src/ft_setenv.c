/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <akalombo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 23:56:42 by akalombo          #+#    #+#             */
/*   Updated: 2020/05/18 23:24:12 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	call_env(char *str)
{
	char		**args;
	char		**new;
	extern char	**environ;

	args = ft_strsplit(str, ' ');
	if (ft_strcmp(args[0], "setenv") == 0)
	{
		new = ft_strsplit(args[1], '=');
		ft_setenv(new[0],new[1], 0);
        if (args)
		    free_(args);
        if (new)
		    free_(new);
		return (0);
	}
    if (args)
	    free_(args);
	return (-1);
}

size_t	count_()
{
	extern char	**environ;
	int		i = 0;

	while (environ[i])
		i++;
	return (i);
}

void	ft_real(char **add, int index)
{
	extern char**	environ;
	int		i;

	i = count_();
	if (index == -1)
	{
        if (environ)
		    free(environ[i]);
		environ[i] = ft_strdup(*add);
	}
	else
	{
        if (environ)
		    free(environ[index]);
		environ[index] = ft_strdup(*add);
	}
	environ[i+1] = NULL;
}

int	ft_setenv(const char *name, const char *value, int overwrite)
{
	char		*tmp = ft_strjoin(name, "=");
	char		*new;
	(void)      overwrite;
	extern char	**environ;

	new = ft_strjoin(tmp, value);
	if (value)
		ft_real(&new, replace_((char *)name));
	else
		ft_real(&tmp, replace_((char *)name));
    if (new)
	    free(new);
    if (tmp)
	    free(tmp);
	return (0);
}
