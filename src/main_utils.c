/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:51:50 by motoko            #+#    #+#             */
/*   Updated: 2023/07/20 15:16:21 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmp_char(char c, char *str)
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

char    **ft_envcpy(char **env)
{
    char    **envcpy;
    int     i;

    i = 0;
    while (env[i])
        i++;
    envcpy = (char **)malloc(sizeof(char *) * (i + 1));
    i = 0;
    while (env[i])
    {
        envcpy[i] = ft_strdup(env[i]);
        i++;
    }
    envcpy[i] = NULL;
    return (envcpy);
}

char    *free_and_join(char *s1, char *s2)
{
    char    *tmp;

    tmp = ft_strjoin(s1, s2);
    free(s1);
    return (tmp);
}