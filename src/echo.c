/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:02:13 by aaudeber          #+#    #+#             */
/*   Updated: 2023/08/09 10:24:29 by motoko           ###   ########.fr       */
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

int	echo(char **tab, char **env)
{
	int	i;
	int	is_return_line;

	i = 1;
	is_return_line = 1;
	(void)env;
	if (!ft_strncmp(tab[1], "-n", 3))
		is_return_line = 0;
	while (tab[i])
	{
		//if (is_double_quote(tab[i]))
		print_line(tab[i]);	
		ft_putchar_fd(' ', 1);
		i++;
	}
	if (is_return_line)
		ft_putchar_fd('\n', 1);
	return (0);
}
