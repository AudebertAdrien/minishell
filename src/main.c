/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus & aaudeber <mcreus@student.42per    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:13:19 by aaudeber          #+#    #+#             */
/*   Updated: 2023/07/03 18:51:15 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	pid_t	process;
	pid_t	wait();

	(void)ac;
	(void)av;
	(void)env;
	while (1)
	{
		static char	*str = (char *)NULL; 
		if (str)
		{
			free(str);
			str = (char *)NULL;
		}
		str = readline("");
		add_history(str);
		process = fork();
		if (str)
		{
			if (process > 0)
				wait();
			if (process == 0)
			if (!strcmp(str, "pwd"))
				execve("/bin/pwd", av, NULL);
	
			//	parse_readline(str);
		}
	}
	return (0);
}
