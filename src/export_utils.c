/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:00:51 by mcreus            #+#    #+#             */
/*   Updated: 2023/07/27 13:01:39 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	dup_table(char ***new_env, int *i, int pos, char **envp)
{
	(*new_env) = malloc(((*i) + 1) * sizeof(char **));
	if ((*new_env) == 0)
		return (0);
	(*new_env)[*i] = 0;
	while ((*i)-- > (pos + 1))
		(*new_env)[*i] = envp[*i];
	free(envp[*i]);
	return (1);
}

void	add_table(char ***new_env, char *add, int *i, char **envp)
{
	(*new_env)[*i] = ft_strdup(add);
	while ((*i)-- > 0)
		(*new_env)[*i] = envp[*i];
}

int	dup_add_table_short(char ***new_env, char *add, int *i, char **envp)
{
	(*new_env) = malloc(((*i) + 1 + 1) * sizeof(char *));
	if (new_env == 0)
		return (0);
	(*new_env)[(*i) + 1] = 0;
	(*new_env)[*i] = ft_strdup(add);
	if (new_env[*i] == 0)
		return (0);
	while ((*i)-- > 0)
		(*new_env)[*i] = envp[*i];
	return (1);
}