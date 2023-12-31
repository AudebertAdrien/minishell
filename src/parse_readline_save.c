/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_readline_save.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:23:46 by aaudeber          #+#    #+#             */
/*   Updated: 2023/08/24 13:41:30 by motoko           ###   ########.fr       */
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

int	ft_count_words(char *str)
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
	tab = (char **)ft_calloc((ft_count_words(str) + 1), sizeof(char *));
	if (!tab)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '"')
		{
			j = 1;
			while (str[i + j] != '"')
				j++;
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


int	count_el(char **tab)
{
	int	i;
	int	ct_cmd;
	int	ct_type_in;
	int	ct_type_out;
	int	ct_file_in;
	int	ct_file_out;

	i = 0;
	ct_cmd = 0;
	ct_type_in = 0;
	ct_type_out = 0;
	ct_file_in = 0;
	ct_file_out = 0;
	while (tab[i])
	{
		if (i == 0)
			ct_cmd++;
		if (ft_strlen(tab[i]) && (!ft_strncmp(tab[i], "|", 1) && tab[i + 1]))
			ct_cmd++;

		if (ft_strlen(tab[i]) == 1 && !ft_strncmp(tab[i], "<", 1) && tab[i - 1])
			ct_file_in++;
		if (ft_strlen(tab[i]) == 2 && !ft_strncmp(tab[i], "<<", 2) && tab[i - 1])
			ct_file_in++;
		if (ft_strlen(tab[i]) == 1 && !ft_strncmp(tab[i], ">", 1) && tab[i + 1])
			ct_file_out++;
		if (ft_strlen(tab[i]) == 2 && !ft_strncmp(tab[i], ">>", 2) && tab[i + 1])
			ct_file_out++;

		if (ft_strlen(tab[i]) == 1 && !ft_strncmp(tab[i], "<", 1))
			ct_type_in++;
		if (ft_strlen(tab[i]) == 2 && !ft_strncmp(tab[i], "<<", 2))
			ct_type_in++;
		if (ft_strlen(tab[i]) == 1 && !ft_strncmp(tab[i], ">", 1))
			ct_type_out++;
		if (ft_strlen(tab[i]) == 2 && !ft_strncmp(tab[i], ">>", 2))
			ct_type_out++;
		i++;
	}
	vars.cmd = malloc(sizeof(char *) * ct_cmd + 1);
	vars.file_in = malloc(sizeof(char *) * ct_file_in + 1);
	vars.file_out = malloc(sizeof(char *) * ct_file_out  + 1);
	vars.type_in = malloc(sizeof(char *) * ct_type_in + 1);
	vars.type_out = malloc(sizeof(char *) * ct_type_out + 1);

	vars.cmd[ct_cmd] = NULL;
	vars.cmd[ct_file_in] = NULL;
	vars.cmd[ct_file_out] = NULL;
	vars.cmd[ct_type_in] = NULL;
	vars.cmd[ct_type_out] = NULL;

	return (0);	
}

int	assign_el(char **tab)
{
	int	i;
	int	ct_cmd;
	int	ct_type_in;
	int	ct_type_out;
	int	ct_file_in;
	int	ct_file_out;

	i = 0;
	ct_cmd = 0;
	ct_type_in = 0;
	ct_type_out = 0;
	ct_file_in = 0;
	ct_file_out = 0;
	while (tab[i])
	{
		if (i == 0)
			vars.cmd[ct_cmd++] = tab[i];
		if (ft_strlen(tab[i]) && (!ft_strncmp(tab[i], "|", 1) && tab[i + 1]))
			vars.cmd[ct_cmd++] = tab[i + 1];

		if (ft_strlen(tab[i]) == 1 && !ft_strncmp(tab[i], "<", 1) && tab[i - 1])
			vars.file_in[ct_file_in++] = tab[i - 1];
		if (ft_strlen(tab[i]) == 2 && !ft_strncmp(tab[i], "<<", 2) && tab[i - 1])
			vars.file_in[ct_file_in++] = tab[i - 1];
		if (ft_strlen(tab[i]) == 1 && !ft_strncmp(tab[i], ">", 1) && tab[i + 1])
			vars.file_out[ct_file_out++] = tab[i + 1];
		if (ft_strlen(tab[i]) == 2 && !ft_strncmp(tab[i], ">>", 2) && tab[i + 1])
			vars.file_out[ct_file_out++] = tab[i + 1];
	
		if (ft_strlen(tab[i]) == 1 && !ft_strncmp(tab[i], "<", 1))
			vars.type_in[ct_type_in++] = tab[i];
		if (ft_strlen(tab[i]) == 1&& !ft_strncmp(tab[i], ">", 1))
			vars.type_out[ct_type_out++] = tab[i];
		if (ft_strlen(tab[i]) == 2 && !ft_strncmp(tab[i], "<<", 2))
			vars.type_in[ct_type_in++] = tab[i];
		if (ft_strlen(tab[i]) == 2 && !ft_strncmp(tab[i], ">>", 2))
			vars.type_out[ct_type_out++] = tab[i];
		i++;
	}
	return (0);	
}

int	ft_create_lst(char **tab, t_list **lst)
{
	int	i;
	int	j;
	int	k;
	int	l;
	t_list	*new;

	i = 0;
	l = 0;
	lst = NULL;
	while (tab[i])
	{
		j = 0;
		while (tab[i + j] && ft_strncmp(tab[i + j], "|", 1)) 
			j++;
		k = 0;
		new = ft_lstnew();
		new->cmd[0] = tab[k++];
		while (k < j)
		{
			new->args[l++] = tab[k++];
		}
		ft_lstadd_back(lst, new);
		i += j + 1;
	}
	return (0);
}

int	parse_readline(char *str)
{
	char	**tab;
	pid_t	process;
	pid_t	wait();
	int	i;
	//int	len_tab;
	t_list	*lst;

	i = 0;
	tab = parse_this_fucking_quote(str);	
	count_el(tab);
	assign_el(tab);
	stats(&vars);

	//process = fork();
	//len_tab = ft_len_tab(vars.cmd);
	ft_create_lst(tab, &lst);
	/*
	while (i < len_tab)
	{
		if (process > 0)
			wait(NULL);
		if (process == 0)
			find_cmd(tab);
		i++;
	}
	*/
	//redirection();
	return (0);
}
