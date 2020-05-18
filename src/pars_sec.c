#include "../inc/minishell.h"

int	built_ins(char *str)
{
	if (ft_strcmp("cd", str) != 0 || ft_strcmp("echo", str) != 0)
		return (-1);
	else if (ft_strcmp("setenv", str) != 0 || ft_strcmp("env", str) != 0)
		return (-1);
	return (0);
}

int	check_(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > 32)
			return (-1);
		i++;
	}
	return (0);
}

int	env_(char *str)
{
	int		i;
	extern char	**environ;

	if (ft_strcmp(str, "env") == 0)
	{
		i = 0;
		while (environ[i])
		{
			ft_putendl(environ[i]);
			i++;
		}
		return (0);
	}
	return (-1);
}

int	len_check(char *str)
{
	size_t	i = 0;

	while (str[i] == ' ' || str[i] == '\t')
		i++;
	i++;
	if (i == ft_strlen(str))
		return (0);
	return (-1);
}
