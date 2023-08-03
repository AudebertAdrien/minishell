/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_readline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:23:46 by aaudeber          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/07/29 18:28:06 by mcreus           ###   ########.fr       */
=======
/*   Updated: 2023/08/02 18:02:58 by motoko           ###   ########.fr       */
>>>>>>> 70cb27f69df80fc1736afd500a17ea17c11bd871
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
	printf("count = %d\n", count);
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

	i = 0;
	while (tab[i])
	{
		printf("=>%s\n", tab[i]);
		i++;
	}
	return (tab);
}

int	parse_readline(char *str, char **envcpy)
{
	char	**tab;
<<<<<<< HEAD

	tab = ft_split(str, ' ');
	find_cmd(tab, envcpy);
	return (0);
}
=======
	int	res;

	tab = ft_split(str, ' ');
	parse_this_fucking_quote(str);	
	res = find_cmd(str, tab, envcpy);
	return (res);
}
>>>>>>> 70cb27f69df80fc1736afd500a17ea17c11bd871
