/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:13:19 by aaudeber          #+#    #+#             */
/*   Updated: 2023/08/09 17:00:49 by motoko           ###   ########.fr       */
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

t_vars	vars;

int	main(int ac, char **av, char **env)
{
	pid_t		process;
	pid_t		wait();
	char		*line;
	static char	*str;

	(void)ac;
	(void)av;
	line = NULL;
	str = (char *)NULL;
	ft_envcpy(env);
	launch();
	while (1)
	{
		if (str)
		{
			free(str);
			str = (char *)NULL;
		}
		line = display_prompt(vars.envcpy);
		str = readline(line);	
		add_history(str);
		process = fork();
		if (str)
		{
			if (process > 0)
				wait(NULL);
			if (process == 0)
			{
				parse_readline(str);
			}
		}
	}
	clear_history();
	return (0);
}
