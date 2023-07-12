/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:19:48 by mcreus & aa       #+#    #+#             */
/*   Updated: 2023/07/12 16:10:02 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(char **args, char **env)
{
	char	*pwd;
	//char	*old_pwd;
	char	*new_pwd;
	char	*path;
	int		i;
	int		index;
	int	len = ft_strlen(getenv("HOME"));
	char	*home_value;

	(void)env;
	//old_pwd = ft_getenv("OLDPWD");
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
	/*else if (!strcmp(args[1], "-"))
	{
		if (!old_pwd)
			return (ft_printf("cd: OLDPWD not set\n"));
		path = old_pwd;
	}
	else
		path = args[1];
	//new_pwd = ft_get_path(pwd, path);
	//if (!new_pwd)
		//return (ft_printf("cd: %s: No such file or directory\n", path));
	//if (chdir(new_pwd) == -1)
		//return (ft_printf("cd: %s: No such file or directory\n", path));
	if (old_pwd)
	{
		free(old_pwd);
		old_pwd = NULL;
	}
	old_pwd = ft_strdup(pwd);
	if (pwd)
	{
		free(pwd);
		pwd = NULL;
	}
	//pwd = ft_strdup(new_pwd);
	if (new_pwd)
	{
		free(new_pwd);
		new_pwd = NULL;
	}*/
	return (0);
}
