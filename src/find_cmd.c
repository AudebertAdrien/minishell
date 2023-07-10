/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:44:53 by aaudeber          #+#    #+#             */
/*   Updated: 2023/07/07 14:04:52 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_cmd(char **tab, char **env)
{
	char	*cmd;

	cmd = tab[0];
	if (!strcmp(cmd, "echo"))
		echo(tab);
	else if (!strcmp(cmd, "cd"))
		ft_cd(tab, env);
	else if (!strcmp(cmd, "pwd"))
		ft_pwd(tab, env);
	return (0);
}
