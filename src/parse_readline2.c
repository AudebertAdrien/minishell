/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_readline2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:23:46 by aaudeber          #+#    #+#             */
/*   Updated: 2023/08/23 15:09:30 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_remove_path_slash(char *str)
{
	char	*ptr;

	DIR *pDir;

	pDir = opendir(str);
	if (pDir)
	{
		if (str[ft_strlen(str) - 1] == '/' && ft_strlen(str) > 1)
		{
			ptr = ft_substr(str, 0 , ft_strlen(str) - 1);
			str = NULL;
			free(str);
			return (ptr);
		}
	}
	return (str);
}

int	handle_cmd(char *str, int start,  int end)
{
	int	i;
	int	j;
	char	*tmp;

	i = start;
	while (str[i] && start < end)
	{
		j = 0;
		/*
		if (str[i] == '"')
		{
			j = 1;
			while (str[i + j] != '"')
				j++;
			tmp = ft_substr(str, i + 1, j - 1);
			tmp = ft_remove_path_slash(tmp);
			i = i + j;
		}
		*/
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' ') && str[i] != '"')
		{
			while (str[i + j] && str[i + j] != ' ')
				j++;
			tmp = ft_substr(str, i, j);
			tmp = ft_remove_path_slash(tmp);
			i = i + j;
		}
		i++;
		ft_printf("%s\n", tmp);
	}
	return (0);
}

int	parse_this_fucking_line(t_list **lst, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] && str[i + j] != '|')
			j++;
		handle_cmd(str, i , i + j - 1);
		i = i + j + 1;
	}
	return (0);
}

int	parse_readline2(char *str)
{
	t_list	*lst;

	parse_this_fucking_line(&lst, str);	
	//stats(&vars);

	//find_cmd(tab);
	return (0);
}
