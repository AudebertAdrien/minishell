/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 20:07:53 by aaudeber          #+#    #+#             */
/*   Updated: 2023/07/03 21:19:18 by aaudeber         ###   ########.fr       */
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

char	*display_prompt(char **env)
{
	char	*line;
	char	*cluster;
	char	*user;
	char	*pwd;

	line = parse_env(env, "SESSION_MANAGER", 15);
	user = getenv("USER");
	pwd = "IN PROGRESS";
	cluster = grep_workstation(line);
	ft_printf("%s@%s:~%s", user, cluster, pwd);
	return (cluster);
}
