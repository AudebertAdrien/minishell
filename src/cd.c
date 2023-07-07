/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:19:48 by mcreus & aa       #+#    #+#             */
/*   Updated: 2023/07/07 12:32:10 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(char **args, char **env)
{
	int		i;
	char	*path;
	char	*old_path;
	char	*new_path;

	i = 0;
	path = NULL;
	old_path = NULL;
	new_path = NULL;
	if (args[1] == NULL)
	{
		path = ft_strdup("/Users/USER");
		chdir(path);
	}
	else if (args[1][0] == '~')
	{
		path = ft_strjoin("/Users/USER", args[1] + 1);
		chdir(path);
	}
	else if (args[1][0] == '-')
	{
		while (env[i])
		{
			if (ft_strncmp(env[i], "OLDPWD=", 7) == 0)
				old_path = ft_strdup(env[i] + 7);
			i++;
		}
		chdir(old_path);
	}
	else
	{
		path = ft_strdup(args[1]);
		chdir(path);
	}
	path = getcwd(path, 0);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PWD=", 4) == 0)
			old_path = ft_strdup(env[i] + 4);
		i++;
	}
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PWD=", 4) == 0)
		{
			free(env[i]);
			env[i] = ft_strjoin("PWD=", new_path);
		}
		if (ft_strncmp(env[i], "OLDPWD=", 7) == 0)
		{
			free(env[i]);
			env[i] = ft_strjoin("OLDPWD=", old_path);
		}
		i++;
	}
	free(path);
	free(old_path);
	free(new_path);
	return (0);
}