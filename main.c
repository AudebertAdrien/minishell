/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:13:19 by aaudeber          #+#    #+#             */
/*   Updated: 2023/06/30 17:22:13 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int	main(int ac, char **av)
{
	pid_t	father;
	pid_t	wait();
	char	*t = getenv("VTE_VERSION");
	printf("%s\n", t);	
	while (1)
	{
		static char	*s = (char *)NULL; 
		if (s)
		{
			free(s);
			s = (char *)NULL;
		}
		s = readline("");
		father = fork();
		if (s)
		{
			if (father > 0)
			{
				wait();
				//printf("%s\n", s);
			}
			if (father == 0)
			{
				if (!strcmp(s, "ls"))
					execve("/bin/ls", av, NULL);
				if (!strcmp(s, "pwd"))
					execve("/bin/pwd", av, NULL);
			}
		}
	}
	return (0);
}

