/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:44:53 by aaudeber          #+#    #+#             */
/*   Updated: 2023/07/03 17:49:12 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_cmd(char **tab)
{
	char	*cmd;

	cmd = tab[0];
	/*
	if (!strcmp(cmd, "ls"))
		execve("/bin/ls", av, NULL);
	if (!strcmp(cmd, "pwd"))
		execve("/bin/pwd", av, NULL);
	*/
	if (!strcmp(cmd, "echo"))
		echo();
	return (0);
}
