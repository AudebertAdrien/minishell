/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:02:13 by aaudeber          #+#    #+#             */
/*   Updated: 2023/08/09 16:52:59 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
int	is_double_quote(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[0] == '"' && str[len - 1] == '"')
		return (1);
	return (0);
}
*/

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
			if (line[i + j] == '"')
				j--;
			str = ft_substr(line, i + 1, j);
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
		}
		i++;
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
		while (tab[i][j])
		{
			if (tab[i][j] != '-')
			{
				j++;
				if (tab[i][j] != 'n')
					return (i);
			}
			else
				return (i)
			j++;
		}
		i++;
	}
	return (i);
}

int	echo(char **tab, char **env)
{
	int	i;
	int	string_index;	

	i = 1;
	(void)env;
	string_index = index_after_option(tab);
	ft_printf("%d\n", string_index);
	while (tab[string_index])
	{
		//if (is_double_quote(tab[i]))
		print_line(tab[i]);	
		ft_putchar_fd(' ', 1);
		i++;
	}
	if (string_index > 1)
		ft_putchar_fd('\n', 1);
	return (0);
}
