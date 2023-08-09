/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:17:51 by mcreus            #+#    #+#             */
/*   Updated: 2023/08/08 14:15:26 by mcreus           ###   ########.fr       */
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

void	unset(char **args, char **env) 
{
	int		args_i;
	char	*line;

	if (args[1])
	{
		line = ft_substr(args[1], 0, len_env(args[1]));
		args_i = ft_get_index(env, line);
		if (args_i)
		{
			free(env[args_i]);
			env[args_i] = NULL;
		}
	}
	else
		ft_putstr_fd("unset: not enough arguments\n", 2);
}