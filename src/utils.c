/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:51:50 by motoko            #+#    #+#             */
/*   Updated: 2023/08/11 18:35:03 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_tab(char **tab)
{
	int	i;

	i = 0;
	ft_printf("|\t");
	ft_printf("\t");
	while (tab[i])
	{
		ft_printf("[%s] ", tab[i]);
		i++;	
	}
	ft_printf("\n");
}

void	stats(t_vars *vars)
{
	ft_printf("\n -----------------------------------------------------------------------\n");
	ft_print_tab(vars->cmd);
	ft_print_tab(vars->file_in);
	ft_printf("\n -----------------------------------------------------------------------\n\n");
}

int	ft_cmp_char(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (0);
		i++;
	}
	return (1);
}

char    *free_and_join(char *s1, char *s2)
{
    char    *tmp;

    tmp = ft_strjoin(s1, s2);
    free(s1);
    return (tmp);
}


int free_tabs(char **env)
{
    int i;

    i = 0;
    while (env[i])
        free(env[i++]);
    return (0);
}

int	**ft_envcpy(char **env)
{
    int     i;

    i = 0;
    while (env[i])
        i++;
    vars.envcpy = (char **)malloc(sizeof(char *) * (i + 1));
    i = 0;
    while (env[i])
    {
        vars.envcpy[i] = ft_strdup(env[i]);
        i++;
    }
    vars.envcpy[i] = NULL;
    return (0);
}

int	ft_get_index(char **env, char *needle)
{
	int		i;
	int		j;
	int		len;
	char		*haystack;

	i = 0;
	len = ft_strlen(needle);
	env[i] = (char *)malloc(sizeof(char) * (len + 1));
	while (env[i])
	{
		haystack = env[i];
		j = 0;
		while (needle[j] && (haystack[j] == needle[j]) && j < len)
			j++;
		if (needle[j] == '\0')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_get_env(char **env, char *needle)
{
	char		*haystack;
	int		i;
	int		j;
	int		len;

	i = 0;
	len = ft_strlen(needle);
	env[i] = (char *)malloc(sizeof(char) * (len + 1));
	while (env[i])
	{
		haystack = env[i];
		j = 0;
		while (needle[j] && (haystack[j] == needle[j]) && j < len)
			j++;
		if (needle[j] == '\0')
			return (env[i]);
		i++;
	}
	return (NULL);
}

