/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:19:48 by mcreus & aa       #+#    #+#             */
/*   Updated: 2023/07/17 11:54:29 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(char **args, char **env)
{
	char	*pwd;
	char	*old_pwd;
	char	*new_pwd;
	char	*path;
	int		i;
	int		index;
	int	len = ft_strlen(getenv("HOME"));
	char	*home_value;

	(void)env;
	path = (char *)malloc(sizeof(char) * len + 1);
	if (!args[1] || !strcmp(args[1], "~"))
	{
		/*path = get_relative_path(pwd, getenv("USER"));
		if (!path)
			return (ft_printf("cd: HOME not set\n"));*/
		path = ft_strdup(ft_get_env(env, "HOME"));
		i = chdir(path);
		index = ft_get_index(env, "PWD");
		pwd = ft_get_env(env, "PWD");
		env[index] = NULL;
		home_value = ft_strjoin("PWD=",ft_substr(path, 5, ft_strlen(path)));
		env[index] = home_value;
	}
	if (!strcmp(args[1], "-"))
	{
		path = ft_strdup(ft_get_env(env, "OLDPWD"));
		i = chdir(path);
		index = ft_get_index(env, "PWD");
		pwd = ft_get_env(env, "PWD");
		env[index] = NULL;
		home_value = ft_strjoin("PWD=",ft_substr(path, 5, ft_strlen(path)));
		env[index] = home_value;
	}
	else
	{
		path = ft_strdup(args[1]);
		i = chdir(path);
		index = ft_get_index(env, "PWD");
		pwd = ft_get_env(env, "PWD");
		env[index] = NULL;
		home_value = ft_strjoin("PWD=",ft_substr(path, 5, ft_strlen(path)));
		env[index] = home_value;
	}
	return (0);
}