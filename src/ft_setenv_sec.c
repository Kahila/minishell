#include "../inc/minishell.h"

int	init_env()
{
	int		i = 0;
	extern char	**environ;
	char		**tmp = environ;

	while(tmp[i])
	{
		if (compar(tmp[i],"XPC_SERVICE_NAME") == 0)
		{
			environ[i] = tmp[i];
			i++;
		}
		environ[i] = ft_strdup(tmp[i]);
		i++;
	}
	g_set = environ;
	return (i);
}

int	compar(char *str, char *str1)
{
	int		i = 0;
	unsigned int	j = 0;
	while(str[i] != '=')
	{
		if ((str[i] == str1[i]) && str1[i] != '\0')
			j++;
		else
			break;
		i++;
	}
	if (j == (ft_strlen(str1)))
		return (0);
	else
		return (-1);
}

int	replace_(char *str)
{
	int		i = 0;
	extern char	**environ;

	while (environ[i])
	{
		if (compar(environ[i], str) == 0)
			return(i);
		i++;
	}
	return (-1);
}

int	free_(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	return (0);
}