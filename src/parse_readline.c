/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_readline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:23:46 by aaudeber          #+#    #+#             */
/*   Updated: 2023/07/03 17:49:15 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_readline(char *str)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_split(str, ' ');
	while (tab[i])
	{
		ft_putstr_fd(tab[i], 1);
		i++;
	}
	find_cmd(tab);
	return (0);
}
