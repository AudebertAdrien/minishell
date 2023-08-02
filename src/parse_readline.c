/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_readline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:23:46 by aaudeber          #+#    #+#             */
/*   Updated: 2023/07/29 18:28:06 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_readline(char *str, char **envcpy)
{
	char	**tab;

	tab = ft_split(str, ' ');
	find_cmd(tab, envcpy);
	return (0);
}