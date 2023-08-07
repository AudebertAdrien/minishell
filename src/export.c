/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 09:55:21 by mcreus            #+#    #+#             */
/*   Updated: 2023/08/07 18:23:20 by mcreus           ###   ########.fr       */
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

char    **ft_envcpy2(char **env, char *str)
{
    char    **envcpy;
    int     i;

    i = 0;
    while (env[i])
        i++;
    envcpy = (char **)malloc(sizeof(char *) * (i + 2));
    i = 0;
    while (env[i])
    {
        envcpy[i] = ft_strdup(env[i]);
        i++;
    }
	envcpy[i] = ft_strdup(str);
	i++;
    envcpy[i] = NULL;
    return (envcpy);
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
			new_env = ft_envcpy2(env, args[1]);
			free_tabs(env);
			env = new_env;
		}
		else
		{
			free(env[args_i]);
			env[args_i] = NULL;
			env[args_i] = args[1];
		}
	}
	else
		print_export(env);
}