/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 20:07:53 by aaudeber          #+#    #+#             */
/*   Updated: 2023/07/07 13:40:26 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*parse_env(char **env, char *needle, int len)
{
	char	*haystack;
	int		i;
	int		j;

	i = 0;
	while (env[i])
	{
		haystack = env[i];
		j = 0;
		while (needle[j] && haystack[j] == needle[j] && j < len)
			j++;
		if (needle[j] == '\0')
			return (env[i]);
		i++;
	}
	return (NULL);
}

char	*grep_workstation(char *line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == '/')
		{
			while (line[i + j] != '.')
				j++;
			return (ft_substr(line, i+1, j - 1));
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

char	*display_prompt(char **env)
{
	char	*session_line;
	char	*user_line;
	char	*pwd_line;

	//char	*relative_path_line;
	char	*cluster_line;
	char	*tilde;

	tilde = "";
	user_line = getenv("USER");
	session_line = parse_env(env, "SESSION_MANAGER", 15);
	pwd_line = getenv("PWD");

	cluster_line = grep_workstation(session_line);
	//relative_path_line = get_relative_path(pwd_line);

	if (is_home_or_root(pwd_line, user_line))
		tilde = "~";
	if (!user_line)
		user_line = "";
	//if (!relative_path_line)
		//relative_path_line = "";

	//ft_printf("%s@%s:%s%s$ ", user_line, cluster_line, tilde, relative_path_line);
	return (NULL);
}
