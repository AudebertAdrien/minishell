/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_readline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:23:46 by aaudeber          #+#    #+#             */
/*   Updated: 2023/08/08 11:24:15 by motoko           ###   ########.fr       */
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
			/* add a condition when "t""x""t" join everything when double
			 * quote are side by side */
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

char	*ft_remove_end_slash(char *str)
{
	char	*ptr;

	if (str[ft_strlen(str) - 1] == '/')
	{
		ptr = ft_substr(str, 0 , ft_strlen(str) - 1);
		str = NULL;
		free(str);
		return (ptr);
	}
	return (str);
}

int	parse_readline(char *str, char **envcpy)
{
	char	**tab;
	int	res;

	//tab = ft_split(str, ' ');
	str = ft_remove_end_slash(str);
	tab = parse_this_fucking_quote(str);	
	res = find_cmd(str, tab, envcpy);
	return (res);
}
