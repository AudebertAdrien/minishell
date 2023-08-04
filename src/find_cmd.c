/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:44:53 by aaudeber          #+#    #+#             */
/*   Updated: 2023/07/28 17:03:55 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_cmd(char **tab, char **envcpy)
{
	char	*cmd;

	cmd = tab[0];
	if (!strcmp(cmd, "echo"))
		echo(tab);
	if (!strcmp(cmd, "cd"))
		ft_cd(tab, envcpy);
	if (!strcmp(cmd, "pwd"))
		ft_pwd(tab);
	if (!strcmp(cmd, "env"))
		ft_env(envcpy);
	if (!strcmp(cmd, "ls"))
		execve("/bin/ls", tab, envcpy);
	if (!strcmp(cmd, "export"))
	{
		if (tab[1])
			export(tab[1], envcpy);
		else
			print_export(envcpy);
	}
	return (0);
}