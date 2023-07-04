/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:19:48 by mcreus & aa       #+#    #+#             */
/*   Updated: 2023/07/04 18:26:57 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_save_oldpath(t_path *pwd)
{
	if (pwd->old_path)
		free(pwd->old_path);
	pwd->old_path = ft_strdup(pwd->path);
}

int	ft_checkchar(t_char *specific)
{
	if (specific->type == '|' || specific->type == '<' || specific->type == '>'
		|| specific->type == '-' || specific->type == '+')
		return (1);
	return (0);
}

char	cd(t_path *pwd, t_var *str)
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
	ft_save_oldpath(pwd);
	if (!str->ch->next ||)
}