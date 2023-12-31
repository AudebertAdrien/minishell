/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:17:51 by mcreus            #+#    #+#             */
/*   Updated: 2023/08/10 18:48:45 by mcreus           ###   ########.fr       */
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

void	ft_unset(char **args) 
{
	int	i;
	int	j;
	char	**new_env;
	
	i = 0;
	j = i;

	if (!args[1])
	{
		ft_putstr_fd("unset: you need put an argument\n", 2);
		return ;
	}
	while (vars.envcpy[i])
		i++;
	new_env = malloc(sizeof(char *) * i + 1);
	i = 0;
	while (vars.envcpy[i])
	{
		if (ft_strncmp(vars.envcpy[i], args[1], len_env(args[1])))
		{
			new_env[j] = ft_strdup(vars.envcpy[i]);
			j++;
		}
		i++;
	}
	free(vars.envcpy);
	vars.envcpy = new_env;
}