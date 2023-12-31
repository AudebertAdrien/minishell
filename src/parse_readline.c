/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_readline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:23:46 by aaudeber          #+#    #+#             */
/*   Updated: 2023/08/24 17:54:20 by motoko           ###   ########.fr       */
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
	/*
	new->cmd[0] = tab[k++];
	while (j < len)
	{
		new->args[l++] = tab[k++];
	}
	ft_lstadd_back(lst, new);
	*/


int	assign_el(char **tab, t_list *new, int start, int len)
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
	while (tab[i + start] && i < len)
	{
		if (ft_strlen(tab[i]) == 1 && !ft_strncmp(tab[i], "<", 1) && tab[i - 1])
			new->file_in[ct_file_in++] = tab[i - 1];
		else if (ft_strlen(tab[i]) == 2 && !ft_strncmp(tab[i], "<<", 2) && tab[i - 1])
			new->file_in[ct_file_in++] = tab[i - 1];
		else if (ft_strlen(tab[i]) == 1 && !ft_strncmp(tab[i], ">", 1) && tab[i + 1])
			new->file_out[ct_file_out++] = tab[i + 1];
		else if (ft_strlen(tab[i]) == 2 && !ft_strncmp(tab[i], ">>", 2) && tab[i + 1])
			new->file_out[ct_file_out++] = tab[i + 1];
		else if (ft_strlen(tab[i]) == 1 && !ft_strncmp(tab[i], "<", 1))
			new->type_in[ct_type_in++] = tab[i];
		else if (ft_strlen(tab[i]) == 1&& !ft_strncmp(tab[i], ">", 1))
			new->type_out[ct_type_out++] = tab[i];
		else if (ft_strlen(tab[i]) == 2 && !ft_strncmp(tab[i], "<<", 2))
			new->type_in[ct_type_in++] = tab[i];
		else if (ft_strlen(tab[i]) == 2 && !ft_strncmp(tab[i], ">>", 2))
			new->type_out[ct_type_out++] = tab[i];
		else
			new->cmd[ct_cmd++] = tab[i];
		i++;
	}
	return (0);	
}

int	count_el(char **tab, t_list *new, int start, int len)
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
	while (tab[i + start] && i < len)
	{
		if (ft_strlen(tab[i]) == 1 && !ft_strncmp(tab[i], "<", 1) && tab[i - 1])
			ct_file_in++;
		else if (ft_strlen(tab[i]) == 2 && !ft_strncmp(tab[i], "<<", 2) && tab[i - 1])
			ct_file_in++;
		else if (ft_strlen(tab[i]) == 1 && !ft_strncmp(tab[i], ">", 1) && tab[i + 1])
			ct_file_out++;
		else if (ft_strlen(tab[i]) == 2 && !ft_strncmp(tab[i], ">>", 2) && tab[i + 1])
			ct_file_out++;

		else if (ft_strlen(tab[i]) == 1 && !ft_strncmp(tab[i], "<", 1))
			ct_type_in++;
		else if (ft_strlen(tab[i]) == 2 && !ft_strncmp(tab[i], "<<", 2))
			ct_type_in++;
		else if (ft_strlen(tab[i]) == 1 && !ft_strncmp(tab[i], ">", 1))
			ct_type_out++;
		else if (ft_strlen(tab[i]) == 2 && !ft_strncmp(tab[i], ">>", 2))
			ct_type_out++;
		else 
			ct_cmd++;	
		i++;
	}
	new->cmd = malloc(sizeof(char *) * ct_cmd + 1);
	new->file_in = malloc(sizeof(char *) * ct_file_in + 1);
	new->file_out = malloc(sizeof(char *) * ct_file_out  + 1);
	new->type_in = malloc(sizeof(char *) * ct_type_in + 1);
	new->type_out = malloc(sizeof(char *) * ct_type_out + 1);

	new->cmd[ct_cmd] = NULL;
	new->file_in[ct_file_in] = NULL;
	new->file_out[ct_file_out] = NULL;
	new->type_in[ct_type_in] = NULL;
	new->type_out[ct_type_out] = NULL;

	return (0);	
}


int	ft_fill_lst(char **tab, t_list **lst, int start, int len)
{
	int	i;
	int	j;
	t_list	*new;

	new = ft_lstnew();
	count_el(tab, new, start, len);
	assign_el(tab, new, start, len);
	ft_lstadd_back(lst, new);
	return (0);
}

int	ft_create_lst(char **tab, t_list **lst)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i + j] && ft_strncmp(tab[i + j], "|", 1)) 
			j++;
		ft_fill_lst(tab, lst , i, j);
		if (tab[i + j] && ft_strncmp(tab[i + j], "|", 1))
			j++;
		i += j;
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

	//process = fork();
	//len_tab = ft_len_tab(vars.cmd);
	ft_create_lst(tab, &lst);
	stats(&lst);
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
