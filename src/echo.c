/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:02:13 by aaudeber          #+#    #+#             */
/*   Updated: 2023/07/30 16:10:54 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_double_quote(char *str)
{
	//int	i;
	int	len;

	//i = 0;
	len = ft_strlen(str);
	if (str[0] == '"' && str[len - 1] == '"')
		return (1);
	return (0);
}

int	find_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/*
int	sizeof_line(char *line, int start, int len)
{
	int	i;

	i = 0;
	while (line[start + i] && start < len)
	{
		if (line[start + i] == ' ')

	}
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
				ft_printf("\n");
				i = i + j;
			}
		} 
		/*
		else 
		{
			ft_putchar_fd(line[i], 1);	
		}
		*/
		i++;
	}

	return (0);
}

int	echo(char **tab, char **env)
{
	int	i;

	i = 1;
	(void)env;
	while (tab[i])
	{
		if (is_double_quote(tab[i]))
			print_line(tab[i]);	

		if (ft_strncmp(tab[1], "-n", 3))
			ft_putchar_fd('\n', 1);
		i++;
	}
	return (0);
}
