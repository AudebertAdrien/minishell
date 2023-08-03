/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:13:19 by aaudeber          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/08/02 14:34:21 by mcreus           ###   ########.fr       */
=======
/*   Updated: 2023/08/01 17:34:40 by motoko           ###   ########.fr       */
>>>>>>> 70cb27f69df80fc1736afd500a17ea17c11bd871
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	pid_t		process;
	pid_t		wait();
	char		**envcpy;
<<<<<<< HEAD
=======
	char		*line;
	static char	*str;
>>>>>>> 70cb27f69df80fc1736afd500a17ea17c11bd871

	(void)ac;
	(void)av;
	line = NULL;
	envcpy = ft_envcpy(env);
	str = (char *)NULL; 
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
				parse_readline(str, envcpy);
		}
	}
	return (0);
}
