/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_readline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:23:46 by aaudeber          #+#    #+#             */
/*   Updated: 2023/08/07 11:39:54 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_count_special_words(char *str)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '"')
		{
			j = 1;
			while (str[i + j] != '"')
				j++;
			count++;
			i = i + j;
		}
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' ') && str[i] != '"')
			count++;
		i++;
	}
	return (count);
}

char	**parse_this_fucking_quote(char *str)
{
	int	i;
	int	j;
	int	k;
	char	**tab;

	i = 0;
	k = 0;
	tab = (char **)ft_calloc((ft_count_special_words(str) + 1), sizeof(char *));
	if (!tab)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '"')
		{
			j = 1;
			while (str[i + j] != '"')
				j++;
			tab[k++] = ft_substr(str, i + 1, j - 1);
			i = i + j;
		}
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' ') && str[i] != '"')
		{
			j = 0;
			while (str[i + j] && str[i + j] != ' ')
				j++;
			tab[k++] = ft_substr(str, i, j);
		}
		i++;
	}
	return (tab);
}

int	parse_readline(char *str, char **envcpy)
{
	char	**tab;
	int	res;

	//tab = ft_split(str, ' ');
	tab = parse_this_fucking_quote(str);	
	res = find_cmd(str, tab, envcpy);
	return (res);
}
