/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:29:29 by mcreus            #+#    #+#             */
/*   Updated: 2023/07/12 14:30:02 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

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