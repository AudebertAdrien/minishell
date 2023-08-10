/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:44:53 by aaudeber          #+#    #+#             */
/*   Updated: 2023/08/09 19:56:25 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_cmd(char **tab)
{
	char	*cmd;
	
	cmd = tab[0];
	if (!strcmp(cmd, "echo"))
		echo(tab, vars.envcpy);
	else if (!strcmp(cmd, "cd"))
		ft_cd(tab, vars.envcpy);
	else if (!strcmp(cmd, "pwd"))
		ft_pwd(tab);
	else if (!strcmp(cmd, "env"))
		ft_env(vars.envcpy);
	else if (!strcmp(cmd, "export"))
		export(tab, vars.envcpy);
	else if (!strcmp(cmd, "ls"))
		execve("/bin/ls", tab, vars.envcpy);
	else if (!strcmp(cmd, "unset"))
		ft_unset(tab);
	//else if (!strcmp(cmd, "exit"))
	//	cmd_exit(tab, envcpy);
	else
	{
		printf("minishell: command not found : %s\n", cmd);
		return (1);
	}
	return (0);
}
