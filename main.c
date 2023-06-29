/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:13:19 by aaudeber          #+#    #+#             */
/*   Updated: 2023/06/29 18:03:55 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
//#include <sys/types.h> 
//#include <sys/wait.h> 

int	main(int ac, char **av)
{
	pid_t	father;
	pid_t	wait();
	
	father = fork();
	if (father > 0)
	{
		wait();
		printf("I'M FATHER\n");

	}
	if (father == 0)
	{
		sleep(10);
		execve("/bin/ls", av, NULL);
	}
	return (0);
}
