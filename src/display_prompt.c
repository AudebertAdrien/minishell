/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 20:07:53 by aaudeber          #+#    #+#             */
/*   Updated: 2023/07/11 11:51:49 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_env(char **env, char *needle)
{
	char	*haystack;
	int		i;
	int		j;
	int		len;

	i = 0;
	len = ft_strlen(needle);
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
			return (&pwd_line[i + j]);
		i++;
	}
	return (NULL);
}

int	cmp_char(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (0);
		i++;
	}
	return (1);
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
			while (cmp_char(session_line[i + j], ".:"))
				j++;
			return (ft_substr(session_line, i + 1, j - 1));
		}
		i++;
	}
	return (NULL);
}

char	is_home_or_root(char *pwd_line, char *user_line)
{
	if (ft_strnstr(pwd_line, user_line, ft_strlen(pwd_line)))
		return (1);
	return (0);
}

char	*get_relative_path(char *pwd_line, char *user_line)
{
	char	*str;

	if (is_home_or_root(pwd_line, user_line))
	{
		str = ft_get_path(pwd_line, user_line);
		printf("=> %s\n", str);
		return (str);
	}
	else 
		return (pwd_line);
}

char	*display_prompt(char **env)
{
	char	*session_line;
	char	*user_line;
//	char	*pwd_line;

//	char	*relative_path_line;
	char	*cluster_line;
//	char	*tilde;

//	tilde = "";
	session_line = ft_get_env(env, "SESSION_MANAGER");
//	pwd_line = getenv("PWD");
	user_line = getenv("USER");

	cluster_line = grep_workstation(session_line);
	/*
	if (is_home_or_root(pwd_line, user_line))
		tilde = "~";
		*/
//	relative_path_line = get_relative_path(pwd_line, user_line);
	//ft_printf("%s@%s:%s%s$ ", user_line, cluster_line, tilde, relative_path_line);
	ft_printf("%s@%s ", user_line, cluster_line);
	return (NULL);
}
