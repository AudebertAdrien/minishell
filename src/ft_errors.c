/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:31:37 by mcreus            #+#    #+#             */
/*   Updated: 2023/07/06 11:34:48 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *ft_errors(t_env *str, int errn, int str_exit)
{
    if (!errn)
        printf("cd: %s: %s\n", strerror(errno));
    else if ()
}