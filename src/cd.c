/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:19:48 by mcreus & aa       #+#    #+#             */
/*   Updated: 2023/07/17 18:00:57 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	change_dir_to_path(char *path, t_var *t_var)
{
	char	*pwd;
	char	*error_msg;
	char	buffer[2048];

	pwd = getcwd(buffer, 2048);
	
	if (chdir(path) != 0 && ft_strchr(path, '>') == NULL)
	{
		error_msg = ft_strjoin("cd: ", path);
		ft_printf("%s\n", error_msg);
		free(error_msg);
		return ;
	}
	pwd = getcwd(buffer, 2048);
	hashmap_insert("PWD", pwd, t_var->env);
}

static void	change_dir_to_oldpwd(char *path)
{
	ft_printf("%s\n", path);
	change_dir_to_path(path);
}

static void	change_dir_to_home(void)
{
	char	*path;
	t_var	*t_var;

	path = ft_strdup(hashmap_search(t_var->env, "HOME"));
	if (path == NULL)
	{
		ft_printf("%s\n", "NO_HOME");
		free(path);
		return ;
	}
	change_dir_to_path(path);
	free(path);
}

void	cd(char	*path)
{
	char	*current_path;
	t_var	*t_var;

	if ((!path) || ft_strcmp(path, "~") == 0)
	{
		change_dir_to_home();
		return ;
	}
	else if (ft_strcmp(path, "-") == 0)
	{
		current_path = ft_strdup(hashmap_search(t_var->env, "OLDPWD"));
		if (current_path == NULL)
		{
			ft_printf("%s\n", "NO_OLDPWD");
			return ;
		}
		change_dir_to_oldpwd(current_path);
	}
	else
	{
		current_path = ft_strdup(path);
		change_dir_to_path(current_path);
	}
	free(current_path);
}