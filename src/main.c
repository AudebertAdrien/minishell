/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:13:19 by aaudeber          #+#    #+#             */
/*   Updated: 2023/08/07 14:40:04 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	launch()
{
	ft_printf("\n\t######################################################################\n");
	ft_printf("\t######################################################################\n");
	ft_printf("\t####                                                              ####\n");
	ft_printf("\t####                                                              ####\n");
	ft_printf("\t####                         MINISHELL                            ####\n");
	ft_printf("\t####                            BY                                ####\n");
	ft_printf("\t####                      TICTAC & MOTOKO                         ####\n");
	ft_printf("\t####                                                              ####\n");
	ft_printf("\t####                                                              ####\n");
	ft_printf("\t######################################################################\n");
	ft_printf("\t######################################################################\n\n");
}

int	main(int ac, char **av, char **env)
{
	pid_t		process;
	pid_t		wait();
	char		**envcpy;
	char		*line;
	static char	*str;

	(void)ac;
	(void)av;
	line = NULL;
	envcpy = ft_envcpy(env);
	str = (char *)NULL;
	launch();
	while (1)
	{
		if (str)
		{
			free(str);
			str = (char *)NULL;
		}
		line = display_prompt(envcpy);
		str = readline(line);	
		add_history(str);
		process = fork();
		if (str)
		{
			if (process > 0)
				wait(NULL);
			if (process == 0)
			{
				parse_readline(str, envcpy);
			}
		}
	}
	rl_clear_history();
	return (0);
}
