/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:17:11 by mcreus            #+#    #+#             */
/*   Updated: 2023/07/12 11:06:54 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *ft_pwd(char **env)
{
    char    *pwd;
    char    *path;
    char    *user;
    char    *workstation;
    char    *session;

    pwd = ft_get_env(env, "PWD");
    path = ft_get_path(pwd, "/");
    user = ft_get_env(env, "USER");
    workstation = ft_get_env(env, "WORKSTATION");
    session = ft_get_env(env, "SESSION");
    if (path)
    {
        ft_printf("%s@%s:%s %s\n", user, workstation, path, session);
        free(path);
        path = NULL;
    }
    else
        ft_printf("%s@%s:%s %s\n", user, workstation, pwd, session);
    if (pwd)
    {
        free(pwd);
        pwd = NULL;
    }
    return (NULL);
}