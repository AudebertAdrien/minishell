/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:19:48 by mcreus & aa       #+#    #+#             */
/*   Updated: 2023/07/06 13:58:52 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_save_oldpath(t_path *path)
{
	if (path->old_path)
		free(path->old_path);
	pwd->old_path = ft_strdup(path->path);
}

int	ft_checkchar(t_char *specific)
{
	if (specific->type == '|' || specific->type == '<' || specific->type == '>'
		|| specific->type == '-' || specific->type == '+')
		return (1);
	return (0);
}

char	cd(t_path *path, t_var *str)
{
	if (str->ch->next && str->ch->next->next)
	{
		if (!ft_checkchar(str->ch->next->next))
		{
			write (2, "cd has too many args\n", 21);
			str->exit = 1;
			return (0);
		}
	}
	ft_save_oldpath(path);
	if (!str->ch->next || ft_strcmp(str->ch->next->ptr, "~"))
		ft_change_path(str, path);
}

void	ft_change_path(t_var *str, t_path *path, char *new_path)
{
	char	*strs;

	strs = ft_strdup(path->path);
	if (!chdir(new_path))
	{
		ft_pwd(str, 0);
		ft_change_env(str, path);
		str->exit = 0;
	}
	else
	{
		chdir(path->path);
		free(path->path);
		path->path = ft_strdup(ft_get_env("PWD", str));
		if (ft_strcmp(str->ch->next->ptr, "/"))
			ft_remove_slash(str);
		ft_errors(str, 0, 1);
	}
	free(str);
}

void	ft_change_env(t_var *str, t_path *path)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str->env[i])
	{
		if (!ft_strncmp(str->env[i], "PWD=", 4))
		{
			tmp = ft_strjoin("PWD=", path->path);
			free(str->env[i]);
			str->env[i] = ft_strdup(tmp);
			free(tmp);
		}
		else if (!ft_strncmp(str->env[i], "OLDPWD=", 7) && path->old_path)
		{
			tmp = ft_strjoin("OLDPWD=", path->old_path);
			free(str->env[i]);
			str->env[i] = ft_strdup(tmp);
			free(tmp);
		}
		i++;
	}
}

void	ft_remove_slash(t_var *str)
{
	int		i;

	i = ft_strlen(str->ch->next->ptr) - 1;
	str->ch->next->ptr[i] = '\0';
}