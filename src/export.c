/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 09:55:21 by mcreus            #+#    #+#             */
/*   Updated: 2023/07/29 18:34:18 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	inline int	getpos(const char *str, const char c)
{
	int	pos;

	pos = ft_strchr(str, c) - str;
	if (pos == 0)
		return (ft_strlen((char *)str));
	return (pos);
}

static char	**dup_add_table(char **envp, char *add, int pos)
{
	char	**new_env;
	int		i;

	i = 0;
	while (envp[i])
		++i;
	if (pos == -1)
	{
		if (!dup_add_table_short(&new_env, add, &i, envp))
			return (0);
	}
	else
	{
		if (!dup_table(&new_env, &i, pos, envp))
			return (0);
		add_table(&new_env, add, &i, envp);
	}
	free(envp);
	return (new_env);
}

void	export_pwd(char ***envp, char *newpwd)
{
	int		pos;

	pos = ft_get_index(*envp, newpwd);
	if (pos != -1)
	{
		*envp = dup_add_table(*envp, newpwd, pos);
	}
}

void	export(char **args, char **envp)
{
	int		i;
	int		pos;

	if (envp == 0)
		return ;
	i = 0;
	while (args[++i])
	{
		pos = ft_get_index(envp, args[i]);
		envp = dup_add_table(envp, args[i], pos);
	}
}