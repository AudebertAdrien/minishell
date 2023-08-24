/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:13:19 by aaudeber          #+#    #+#             */
/*   Updated: 2023/08/23 15:14:57 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_vars	vars;

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
		if (str)
			parse_readline(str);
	}
	rl_clear_history();
	return (0);
}
