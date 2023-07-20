/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:19:48 by mcreus & aa       #+#    #+#             */
/*   Updated: 2023/07/17 12:40:56 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_last_slash(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '/')
			count = i;
		i++;
	}
	return (count);
}

int	ft_cd(char **args, char **env)
{
	char	*pwd;
	char	*old_pwd;
	char	*path;

	char	*new_pwd;

	int		pwd_i;
	int		old_pwd_i;

	(void)env;
	path = ft_strdup(ft_get_env(env, "HOME"));
	pwd = ft_get_env(env, "PWD");
	old_pwd = ft_get_env(env, "OLDPWD");

	pwd_i = ft_get_index(env, "PWD");
	old_pwd_i = ft_get_index(env, "OLDPWD");
	if (!args[1] || !strcmp(args[1], "~"))
	{
		new_pwd = ft_strjoin("PWD=",ft_substr(path, 5, ft_strlen(path)));
		env[pwd_i] = NULL;
		free(pwd);
		env[pwd_i] = new_pwd;

		chdir(path);

		/*
		env[old_pwd_i] = NULL;
		old_pwd = ft_strjoin("OLDPWD=",ft_substr(pwd, 5, ft_strlen(pwd)));
		env[old_pwd_i] = old_pwd;
		*/
	
	}
	
	if (args[1] && !strcmp(args[1], ".."))
	{
		new_pwd = ft_strjoin("PWD=",ft_substr(pwd, 4, find_last_slash(pwd) - 4));
		env[pwd_i] = NULL;
		free(pwd);
		env[pwd_i] = new_pwd;

		chdir(new_pwd);
	
		/*
		env[old_pwd_i] = NULL;
		free(old_pwd);
		old_pwd = ft_strjoin("OLDPWD=",ft_substr(pwd, 5, ft_strlen(pwd)));
		env[old_pwd_i] = old_pwd;
		*/
	}
	
	
	return (0);
}
