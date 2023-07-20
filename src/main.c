/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:13:19 by aaudeber          #+#    #+#             */
/*   Updated: 2023/07/20 13:07:26 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	pid_t		process;
	pid_t		wait();
	static char	*str;
	char		**envcpy;

	(void)ac;
	(void)av;
	envcpy = ft_envcpy(env);
	str = (char *)NULL; 
	while (1)
	{
		if (str)
		{
			free(str);
			str = (char *)NULL;
		}
		display_prompt(envcpy);
		str = readline(" ");
		add_history(str);
		process = fork();
		if (str)
		{
			if (process > 0)
				wait();
			if (process == 0)
				parse_readline(str, envcpy);
		}
	}
	return (0);
}
