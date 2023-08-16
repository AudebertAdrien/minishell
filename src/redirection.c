/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:28:55 by mcreus            #+#    #+#             */
/*   Updated: 2023/08/16 13:46:46 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redirection(void)
{
	pid_t	process;
	pid_t	wait();
	int	fd;
	char	*filename;
	char	*cmd;
	char	*args[3];

	fd = -1;
	filename = "./output.txt";

	cmd = "/bin/ls";
	args[0] = cmd;
	args[1] = "-ls";
	args[2] = NULL;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 00700);
	if (fd == -1)
	{
		perror("error1");
		return (-1);
	}
	process = fork();
	if (process == -1)
	{
		close (fd);
		perror("error2");
	}
	if (process == 0)
	{
		dup2(fd, STDOUT_FILENO);
		execve(cmd, args, NULL);
		perror("error3");
	}
	close(fd);
	wait(NULL);
	return (0);
}
