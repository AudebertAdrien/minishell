/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:02:13 by aaudeber          #+#    #+#             */
/*   Updated: 2023/07/03 19:28:19 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo(char **tab)
{
	ft_printf("ECHO\n");	
	int	i;

	i = 1;
	while (tab[i])
	{
		ft_putstr_fd(tab[i], 1);
		ft_putchar_fd('\n', 1);
		//rl_on_new_line();
		//rl_replace_line("", 0);
		//rl_clear_message();
		i++;
	}
	return (0);
}
