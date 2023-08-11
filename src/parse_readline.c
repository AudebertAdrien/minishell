/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_readline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:23:46 by aaudeber          #+#    #+#             */
/*   Updated: 2023/08/11 18:34:16 by motoko           ###   ########.fr       */
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
	char	*tmp;

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
			tmp = ft_substr(str, i + 1, j - 1);
			tab[k++] = ft_remove_path_slash(tmp);
			i = i + j;
		}
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' ') && str[i] != '"')
		{
			j = 0;
			while (str[i + j] && str[i + j] != ' ')
				j++;
			tmp = ft_substr(str, i, j);
			tab[k++] = ft_remove_path_slash(tmp);
		}
		i++;
	}
	return (tab);
}

void	assign_vars(char **tab)
{
	int	i;
	int	j;
	int	c;
	int	f;
	int	count_cmds;
	int	count_files;

	i = 0;
	j = 0;
	c = 0;
	f = 0;
	count_cmds = 0;
	count_files = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (i == 0 && j == 0)
				count_cmds++;
			if (tab[i][j] == '|' && tab[i + 1])
				count_cmds++;
			if (ft_strnstr(&tab[i][j], ">>", 2) && tab[i + 1])
				count_files++;
			j++;
		}
		i++;
	}
	vars.cmd = malloc((sizeof(char *) * count_cmds) + 1);
	vars.file_in = malloc((sizeof(char *) * count_files) + 1);
	i = 0;
	while (tab[i])
	{
		if (i == 0)
			vars.cmd[c++] = tab[i];
		if (tab[i][0] == '|' && tab[i + 1])
			vars.cmd[c++] = tab[i + 1];
		if (ft_strnstr(&tab[i][j], ">>", 2) && tab[i + 1])
			vars.file_in[f++] = tab[i + 1];
		i++;
	}
	vars.cmd[c] = NULL;
	vars.file_in[f] = NULL;
}

int	parse_readline(char *str)
{
	char	**tab;
	int	res;

	tab = parse_this_fucking_quote(str);	
	assign_vars(tab);
	stats(&vars);
	res = find_cmd(tab);
	return (res);
}
