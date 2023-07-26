/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:15:09 by mcreus            #+#    #+#             */
/*   Updated: 2023/07/26 11:46:49 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_len(void)
{
	char	**env;
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

int	check_env(char *str)
{
	char	*head;

	head = ft_strchr(str, '=');
	if (!head || (head == str))
		return (0);
	while (*str)
	{
		if (is_whitespace(*str))
			return (0);
		str++;
	}
	return (1);
}

void	add_env(char *str)
{
	int		i;
	char	**new_env;
	char	**env;

	i = 0;
	new_env = ft_calloc(sizeof(char *), env_len() + 2);
	while (env[i++])
		new_env[i] = ft_strdup(env[i]);
	new_env[i] = ft_strdup(str);
	free_array(env);
	env = new_env;
}

int	is_include(char *str)
{
	int		i;
	int		j;
	char	**env;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && str[j])
		{
			if (str[j] == '=' && env[i][j] == '=')
				return (i);
			if (str[j] != env[i][j])
				break ;
			j++;
		}
		i++;
	}
	return (-1);
}

void	export(char **input)
{
	int		pos;
	char	**env;
	t_var	*t_var;

	input++;
	while (*input)
	{
		if (check_env(*input))
		{
			pos = is_include(*input);
			if (pos != -1)
				env[pos] = ft_strdup(*input);
			else
				add_env(*input);
		}
		input++;
	}
	set_paths();
	if (t_var->parent_pid != getpid())
		exit(1);
}

void	set_paths(void)
{
	char	*path;
	t_path	*t_path;

	if (t_path->path)
		free_array(t_path->path);  
	path = get_env("PATH");
	if (!(*path))
		t_path->path = 0;
	else
		t_path->path = ft_split(path, ':');
	free(path);
}

void	free_array(char **args)
{
	int	i;

	i = 0;
	while (args[i++])
		free(args[i]);
	free(args);
}

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t');
}

char	*get_env(char *str)
{
	int		i;
	int		j;
	char	*strp;
	char	**env;

	i = 0;
	j = 0;
	strp = ft_strjoin(str, "=");
	while (env[i++])
	{
		if (!ft_strncmp(env[i], strp, ft_strlen(strp)))
		{
			while (env[i][j] != '=')
				j++;
			free(strp);
			return (ft_strdup(&env[i][j + 1]));
		}
	}
	free(strp);
	return (ft_calloc(sizeof(char *), 1));
}
