/*                                                        :::      ::::::::   */
/*   display_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 20:07:53 by aaudeber          #+#    #+#             */
/*   Updated: 2023/07/19 11:11:46 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	is_home_or_root(char *pwd_line, char *user_line)
{
	if (ft_strnstr(pwd_line, user_line, ft_strlen(pwd_line)))
		return (1);
	return (0);
}

int	ft_get_index(char **env, char *needle)
{
	int		i;
	int		j;
	int		len;
	char		*haystack;

	i = 0;
	len = ft_strlen(needle);
	env[i] = (char *)malloc(sizeof(char) * (len + 1));
	while (env[i])
	{
		haystack = env[i];
		j = 0;
		while (needle[j] && (haystack[j] == needle[j]) && j < len)
			j++;
		if (needle[j] == '\0')
			return (i);
		i++;
	}
	return (0);
}

char	*ft_get_env(char **env, char *needle)
{
	char		*haystack;
	int		i;
	int		j;
	int		len;

	i = 0;
	len = ft_strlen(needle);
	env[i] = (char *)malloc(sizeof(char) * (len + 1));
	while (env[i])
	{
		haystack = env[i];
		j = 0;
		while (needle[j] && (haystack[j] == needle[j]) && j < len)
			j++;
		if (needle[j] == '\0')
			return (env[i]);
		i++;
	}
	return (NULL);
}

char	*grep_workstation(char *session_line)
{
	int		i;
	int		j;
	char		*str;

	i = 0;
	j = 0;
	str = "";
	if (APPLE)
		return (str);
	while (session_line[i])
	{
		if (session_line[i] == '/')
		{
			while (ft_cmp_char(session_line[i + j], ":."))
				j++;
			return (ft_substr(session_line, i + 1, j - 1));
		}
		i++;
	}
	return (NULL);
}

char	*ft_get_path(char *pwd_line, char *user_line)
{
	int		i;
	int		j;

	i = 0;
	while (pwd_line[i])
	{
		j = 0;
		while (user_line[j] && (pwd_line[i + j] == user_line[j]))
			j++;
		if (user_line[j] == '\0')
		{
			if (pwd_line[i + j] == '\0')
				return (&pwd_line[i + j]);
			else
				return (ft_substr(&pwd_line[i + j], 1, ft_strlen(&pwd_line[i + j])));
		}
		i++;
	}
	return (NULL);
}

char	*get_relative_path(char *pwd_line, char *user_line)
{
	char	*str;

	if (is_home_or_root(pwd_line, user_line))
	{
		str = ft_get_path(pwd_line, user_line);
		return (str);
	}
	else 
	{
		str = ft_substr(pwd_line, 4, ft_strlen(pwd_line));
		if (!str[0])
			str = "/";
		return (str);
	}
}

char	*get_user_line(char **env)
{
	int	i;
	char	*user_line;

	i = 0;
    	user_line = ft_get_env(env, "USER");
	if (!user_line)
		user_line = "";
	while (user_line[i])
	{
		if (user_line[i] == '=')
			return (ft_substr(user_line, i + 1, ft_strlen(user_line)));
		i++;
	}
	return (user_line);
}

char	*ft_join_all_part(char *usr, char *cluster, char *tilde, char *path)
{
	char	*str;

	str = free_and_join(usr, "@");
	str = free_and_join(str, cluster);
	str = free_and_join(str, ":");
	str = free_and_join(str, cluster);
	str = free_and_join(str, tilde);
	str = free_and_join(str, path);
	str = free_and_join(str, "$");
	str = free_and_join(str, " ");
	return (str);
}

char	*display_prompt(char **env)
{
	char	*tilde;
	char	*session_line;
	char	*pwd_line;
	char	*cluster_line;
	char	*relative_path_line;
	char	*user_line;
	char	*returned_line;

	returned_line = NULL;
	tilde = "";
    	session_line = ft_get_env(env, "SESSION_MANAGER");
    	pwd_line = ft_get_env(env, "PWD");

	user_line = get_user_line(env);
		
	cluster_line = grep_workstation(session_line);

	if (is_home_or_root(pwd_line, user_line))
	    tilde = "~";

	relative_path_line = get_relative_path(pwd_line, user_line);

	returned_line = ft_join_all_part(user_line, cluster_line, tilde, relative_path_line);
	return (returned_line);
}
