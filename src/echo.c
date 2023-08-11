/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:02:13 by aaudeber          #+#    #+#             */
/*   Updated: 2023/08/11 16:54:37 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_line(char *line)
{
	int	i;
	int	j;
	char	*str;

	i = 0;
	while (line[i])
	{
		if (line[i] == '$')
		{
			j = 1;
			while (line[i + j] && (line[i + j] != ' ' && line[i + j] != '"'))
				j++;
			str = ft_substr(line, i + 1, j - 1);
			if (getenv(str))
			{
				ft_printf("%s", getenv(str));
				i = i + j;
			}
		} 
		else
		{
			if (!(line[i] == '"'))
				ft_putchar_fd(line[i], 1);
			i++;
		}
	}

	return (0);
}

int	index_after_option(char **tab)
{
	int	i;
	int	j;

	i = 1;
	while (tab[i])
	{
		j = 0;
		if (tab[i][j++] == '-')
		{
			while (tab[i][j] == 'n')
				j++;
			if (tab[i][j] && tab[i][j] != 'n')
				return (i);
		}
		else
			return (i);
		i++;
	}
	return (0);
}

int	echo(char **tab, char **env)
{
	int	i;
	int	string_index;	

	i = 1;
	(void)env;
	string_index = index_after_option(tab);
	while (tab[i])
	{
		if (i >= string_index)
		{
			print_line(tab[i]);	
			ft_putchar_fd(' ', 1);
		}
		i++;
	}
	if (string_index == 1)
		ft_putchar_fd('\n', 1);
	return (0);
}
