/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:19:48 by mcreus & aa       #+#    #+#             */
/*   Updated: 2023/07/20 11:01:14 by mcreus           ###   ########.fr       */
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
	int		i;

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
		new_pwd = ft_strjoin("PWD=",ft_substr(pwd, 4, find_last_slash(pwd) - 4));
		env[pwd_i] = NULL;
		free(pwd);
		env[pwd_i] = new_pwd;

		chdir(new_pwd);
		free(new_pwd);
	
		/*env[old_pwd_i] = NULL;
		free(old_pwd);
		old_pwd = ft_strjoin("OLDPWD=",ft_substr(pwd, 5, ft_strlen(pwd)));
		env[old_pwd_i] = old_pwd;*/
	}
	
	else if (args[1] && !ft_strcmp(args[1], "-"))
	{
		
		new_pwd = ft_strjoin("PWD=",ft_substr(old_pwd, 7, ft_strlen(old_pwd)));
		env[pwd_i] = NULL;
		free(pwd);
		env[pwd_i] = new_pwd;
		chdir(new_pwd);
		free(new_pwd);

		env[old_pwd_i] = NULL;
		free(old_pwd);
		old_pwd = ft_strjoin("OLDPWD=",ft_substr(pwd, 5, ft_strlen(pwd)));
		env[old_pwd_i] = old_pwd;
	}
	else
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

/*char	*check_dir(char *arg)
{
	char	*dir;

	if (arg == NULL || ft_strcmp(arg, "~") == 0)
		dir = get_env_value("$HOME");
	else if (ft_strcmp(arg, "-") == 0)
	{
		dir = get_env_value("$OLDPWD");
		ft_putstr_fd(dir, 1);
		ft_putstr_fd("\n", 1);
	}
	else
		dir = ft_strdup(arg);
	return (dir);
}

void	set_pwd_and_oldpwd(char *oldpwd, char *dir)
{
	char	**new_env;

	if (ft_strcmp(dir, "."))
	{
		new_env = set_env("OLDPWD", oldpwd);
		free(oldpwd);
		oldpwd = getcwd(NULL, 0);
		free_split(g_var.env);
		init_env(new_env);
		free_split(new_env);
		new_env = set_env("PWD", oldpwd);
		free_split(g_var.env);
		init_env(new_env);
		free_split(new_env);
	}
	free(oldpwd);
	free(dir);
}

int	ft_cd(char *arg)
{
	char	*dir;
	char	*oldpwd;

	oldpwd = NULL;
	dir = check_dir(arg);
	if (access(dir, F_OK) == -1)
	{
		error_cd(dir, 1);
		return (1);
	}
	if (access(dir, R_OK) == -1)
	{
		error_cd(dir, 2);
		return (1);
	}
	oldpwd = getcwd(NULL, 0);
	if (chdir(dir) == -1)
	{
		error_cd(dir, 3);
		free(oldpwd);
		return (1);
	}
	set_pwd_and_oldpwd(oldpwd, dir);
	return (0);
}

void	error_cd(char *file, int err_type)
{
	if (err_type == 1)
	{
		ft_putstr_fd("cd: No such file or directory\n", 2);
	}
	if (err_type == 2)
	{
		ft_putstr_fd("cd: Permission denied\n", 2);
	}
	if (err_type == 3)
	{
		ft_putstr_fd("cd: Not a directory\n", 2);
	}
	free(file);
}
*/