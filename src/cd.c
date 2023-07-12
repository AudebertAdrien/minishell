/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:19:48 by mcreus & aa       #+#    #+#             */
/*   Updated: 2023/07/11 18:41:33 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(char **args, char **env)
{
	char	*pwd;
	char	*old_pwd;
	char	*new_pwd;
	char	*path;

	pwd = ft_get_env(env, "PWD");
	old_pwd = ft_get_env(env, "OLDPWD");
	if (!args[1] || !strcmp(args[1], "~"))
	{
		path = ft_get_env(env, "HOME");
		if (!path)
			return (ft_printf("cd: HOME not set\n"));
	}
	else if (!strcmp(args[1], "-"))
	{
		if (!old_pwd)
			return (ft_printf("cd: OLDPWD not set\n"));
		path = old_pwd;
	}
	else
		path = args[1];
	new_pwd = ft_get_path(pwd, path);
	if (!new_pwd)
		return (ft_printf("cd: %s: No such file or directory\n", path));
	if (chdir(new_pwd) == -1)
		return (ft_printf("cd: %s: No such file or directory\n", path));
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
	pwd = ft_strdup(new_pwd);
	if (new_pwd)
	{
		free(new_pwd);
		new_pwd = NULL;
	}
	return (0);
}