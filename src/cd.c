/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:19:48 by mcreus & aa       #+#    #+#             */
/*   Updated: 2023/07/20 13:30:10 by mcreus           ###   ########.fr       */
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
	char	*str;

	char	*new_pwd;

	int		pwd_i;
	int		old_pwd_i;

	(void)env;
	path = ft_strdup(ft_get_env(env, "HOME"));
	pwd = ft_get_env(env, "PWD");
	old_pwd = ft_get_env(env, "OLDPWD");

	pwd_i = ft_get_index(env, "PWD");
	old_pwd_i = ft_get_index(env, "OLDPWD");
	if (!args[1] || !ft_strcmp(args[1], "~"))
	{
		new_pwd = ft_strjoin("PWD=",ft_substr(path, 5, ft_strlen(path)));
		env[pwd_i] = NULL;
		free(pwd);
		env[pwd_i] = new_pwd;

		chdir(path);

		/*env[old_pwd_i] = NULL;
		old_pwd = ft_strjoin("OLDPWD=",ft_substr(pwd, 5, ft_strlen(pwd)));
		env[old_pwd_i] = old_pwd;*/
	
	}
	else if (args[1] && !ft_strcmp(args[1], ".."))
	{
		env[old_pwd_i] = NULL;
		free(old_pwd);
		old_pwd = ft_strjoin("OLDPWD=",ft_substr(pwd, 5, ft_strlen(pwd)));
		env[old_pwd_i] = old_pwd;
		
		new_pwd = NULL;
		free(new_pwd);
		new_pwd = ft_strjoin("PWD=",ft_substr(pwd, 4, find_last_slash(pwd) - 4));
		env[pwd_i] = NULL;
		free(pwd);
		env[pwd_i] = new_pwd;

		chdir(new_pwd);
		//free(new_pwd);
	}
	
	else if (args[1] && !ft_strcmp(args[1], "-"))
	{
		new_pwd = NULL;
		free(new_pwd);
		new_pwd = ft_strjoin("PWD=",ft_substr(old_pwd, 7, ft_strlen(old_pwd)));
		env[old_pwd_i] = NULL;
		free(old_pwd);
		old_pwd = ft_strjoin("OLDPWD=",ft_substr(pwd, 5, ft_strlen(pwd)));
		env[old_pwd_i] = old_pwd;
		env[pwd_i] = NULL;
		free(pwd);
		env[pwd_i] = new_pwd;
		chdir(new_pwd);
		//free(new_pwd);
	}
	else if (args[1] && args[1][i])
	{
		str = ft_strjoin(pwd, "/");
		path = ft_strjoin(str, args[1]);
		new_pwd = ft_strjoin("PWD=",ft_substr(path, 4, ft_strlen(path)));
		env[pwd_i] = NULL;
		free(pwd);
		env[pwd_i] = new_pwd;
		chdir(new_pwd);
	}
	return (0);
}
