/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:44:53 by aaudeber          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/08/02 13:33:47 by mcreus           ###   ########.fr       */
=======
/*   Updated: 2023/08/01 17:39:36 by motoko           ###   ########.fr       */
>>>>>>> 70cb27f69df80fc1736afd500a17ea17c11bd871
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_cmd(char *orig_str, char **tab, char **envcpy)
{
	char	*cmd;
	
	cmd = tab[0];
	if (!strcmp(cmd, "echo"))
		echo(orig_str, tab, envcpy);
	else if (!strcmp(cmd, "cd"))
		ft_cd(tab, envcpy);
	else if (!strcmp(cmd, "pwd"))
		ft_pwd(tab);
	else if (!strcmp(cmd, "env"))
		ft_env(envcpy);
	else if (!strcmp(cmd, "ls"))
		execve("/bin/ls", tab, envcpy);
<<<<<<< HEAD
=======
	else if (!strcmp(cmd, "export"))
		print_export(envcpy);
>>>>>>> 70cb27f69df80fc1736afd500a17ea17c11bd871
	else if (!strcmp(cmd, "exit"))
		cmd_exit(tab, envcpy);
	else if (!strcmp(cmd, "export") && !tab[1])
		print_export(envcpy);
	else if (!strcmp(cmd, "export") && tab[1])
		export(tab, envcpy);
	else
	{
		printf("minishell: command not found : %s\n", cmd);
		return (1);
	}
	return (0);
}
