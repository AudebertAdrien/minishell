/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:02:13 by aaudeber          #+#    #+#             */
/*   Updated: 2023/07/27 17:44:13 by motoko           ###   ########.fr       */
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
	//int	len;
	char	*str;

	i = 0;
	//len = 0;
	while (line[i])
	{
		if (line[i] == '$')
		{
			j = 0;
			i++;
			while (line[i + j] && (line[i + j] != ' ' || line[i + j] != '"'))
			{
//				ft_putchar_fd(line[i + j], 1);
				j++;
			}
			if (line[i + j] == '"')
				j--;
			//len = sizeof_line(line,i ,j);

			str = ft_substr(line, i, i + j);
			if (str)
				printf("1 %s\n", str);
				//printf("2 %s\n", getenv(str));
		}
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
		{
			print_line(tab[i]);	
		}
		//ft_putstr_fd(tab[i], 1);
		if (ft_strncmp(tab[1], "-n", 3))
			ft_putchar_fd('\n', 1);
		i++;
	}
	return (0);
}
