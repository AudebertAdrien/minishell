/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:17:11 by mcreus            #+#    #+#             */
/*   Updated: 2023/07/13 11:41:12 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *ft_pwd(char **env)
{
    char    *pwd;
    int     index;

    index = ft_get_index(env, "PWD");
    pwd = ft_get_env(env, "PWD");
    env[index] = NULL;
    env[index] = ft_strjoin("PWD=", getcwd(NULL, 0));
    return (pwd);
}