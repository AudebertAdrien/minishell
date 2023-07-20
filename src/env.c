/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:01:35 by mcreus            #+#    #+#             */
/*   Updated: 2023/07/12 16:01:53 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_env(char **env)
{
    int i;

    i = 0;
    while (env[i])
    {
        ft_printf("%s\n", env[i]);
        i++;
    }
}