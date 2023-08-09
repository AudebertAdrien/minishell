/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 09:55:21 by mcreus            #+#    #+#             */
/*   Updated: 2023/08/09 16:48:28 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	len_env(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (i);
}

char    **ft_duplicate_env(char **env, char *str)
{
    char    **tmp;
    int     i;

    i = 0;
    while (env[i])
        i++;
    tmp = (char **)malloc(sizeof(char *) * (i + 2));
    i = 0;
    while (env[i])
    {
        tmp[i] = ft_strdup(env[i]);
        i++;
    }
	tmp[i] = ft_strdup(str);
		i++;
    tmp[i] = NULL;
    return (tmp);
}

void	export(char **args, char **env)
{
	int		args_i;
	char	*line;
	char	**new_env;

	if (args[1])
	{
		line = ft_substr(args[1], 0, len_env(args[1]));
		args_i = ft_get_index(env, line);
		if (args_i == -1)
		{
			new_env = ft_duplicate_env(env, args[1]);
			vars.envcpy = new_env;
		}
		else
		{
			free(vars.envcpy[args_i]);
			vars.envcpy[args_i] = NULL;
			vars.envcpy[args_i] = args[1];
		}
	}
	else
		print_export(vars.envcpy);
}