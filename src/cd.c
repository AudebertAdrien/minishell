/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:19:48 by mcreus & aa       #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/08/02 13:39:45 by mcreus           ###   ########.fr       */
=======
/*   Updated: 2023/07/31 14:00:23 by motoko           ###   ########.fr       */
>>>>>>> 70cb27f69df80fc1736afd500a17ea17c11bd871
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

	int	pwd_i;
	int	old_pwd_i;

	(void)env;
	path = ft_strdup(ft_get_env(env, "HOME"));
	pwd = ft_get_env(env, "PWD");
	old_pwd = ft_get_env(env, "OLDPWD");

	pwd_i = ft_get_index(env, "PWD");
	old_pwd_i = ft_get_index(env, "OLDPWD");
	if (!args[1] || !ft_strcmp(args[1], "~"))
	{
		env[old_pwd_i] = NULL;
		free(old_pwd);
		old_pwd = ft_strjoin("OLDPWD=",ft_substr(pwd, 4, ft_strlen(pwd)));
		env[old_pwd_i] = old_pwd;
		
		new_pwd = ft_strjoin("PWD=",ft_substr(path, 5, ft_strlen(path)));
		env[pwd_i] = NULL;
		free(pwd);
		env[pwd_i] = new_pwd;
		
		chdir(ft_substr(new_pwd, 4, ft_strlen(new_pwd)));
	}
	else if (args[1] && !ft_strcmp(args[1], ".."))
	{
		env[old_pwd_i] = NULL;
		free(old_pwd);
		old_pwd = ft_strjoin("OLDPWD=",ft_substr(pwd, 4, ft_strlen(pwd)));
		env[old_pwd_i] = old_pwd;
		
		new_pwd = NULL;
		free(new_pwd);
		new_pwd = ft_strjoin("PWD=",ft_substr(pwd, 4, find_last_slash(pwd) - 4));
		env[pwd_i] = NULL;
		free(pwd);
		env[pwd_i] = new_pwd;

		chdir(ft_substr(new_pwd, 4, ft_strlen(new_pwd)));
	}
	else if (args[1] && !ft_strcmp(args[1], "-"))
	{
		new_pwd = NULL;
		free(new_pwd);
		new_pwd = ft_strjoin("PWD=",ft_substr(old_pwd, 7, ft_strlen(old_pwd)));
		env[old_pwd_i] = NULL;
		free(old_pwd);
		old_pwd = ft_strjoin("OLDPWD=",ft_substr(pwd, 4, ft_strlen(pwd)));
		env[old_pwd_i] = old_pwd;
		env[pwd_i] = NULL;
		free(pwd);
		env[pwd_i] = new_pwd;
		chdir(ft_substr(new_pwd, 4, ft_strlen(new_pwd)));
	}
	else if (!ft_strcmp(args[1], "/"))
            ft_printf ("Cannot open root directory with '%s'\n", args[1]);
	else
	{
	//struct dirent *pDirent;
        DIR *pDir;

        pDir = opendir (args[1]);
        if (pDir == NULL) {
            printf ("Cannot open directory '%s'\n", args[1]);
            return 1;
        }
		new_pwd = NULL;
		free(new_pwd);
		new_pwd = ft_strjoin(pwd, "/");
		new_pwd = ft_strjoin(new_pwd, args[1]);
		env[pwd_i] = NULL;
		free(pwd);
		env[pwd_i] = new_pwd;
		
        chdir(ft_substr(new_pwd, 4, ft_strlen(new_pwd)));
        closedir (pDir);
    }
	return (0);
}
