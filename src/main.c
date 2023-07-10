/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:13:19 by aaudeber          #+#    #+#             */
/*   Updated: 2023/07/10 15:29:58 by motoko           ###   ########.fr       */
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
		//display_prompt(env);
		str = readline("");
		add_history(str);
		process = fork();
		if (str)
		{
			if (process > 0)
				wait();
			if (process == 0)
		parse_readline(str);
		}
	}
	return (0);
}
