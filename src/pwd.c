/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:17:11 by mcreus            #+#    #+#             */
/*   Updated: 2023/07/07 12:33:07 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *ft_pwd(char **args, char **env)
{
    char    *path;
    int     i;

    i = 0;
    path = NULL;
    if (args[1] == NULL)
    {
        path = ft_strdup("/Users/USER");
        chdir(path);
    }
    else if (args[1][0] == '~')
    {
        path = ft_strjoin("/Users/USER", args[1] + 1);
        chdir(path);
    }
    else if (args[1][0] == '-')
    {
        while (env[i])
        {
            if (ft_strncmp(env[i], "OLDPWD=", 7) == 0)
                path = ft_strdup(env[i] + 7);
            i++;
        }
        chdir(path);
    }
    else
    {
        path = ft_strdup(args[1]);
        chdir(path);
    }
    path = getcwd(path, 0);
    i = 0;
    while (env[i])
    {
        if (ft_strncmp(env[i], "PWD=", 4) == 0)
            path = ft_strdup(env[i] + 4);
        i++;
    }
    i = 0;
    while (env[i])
    {
        if (ft_strncmp(env[i], "OLDPWD=", 7) == 0)
            path = ft_strdup(env[i] + 7);
        i++;
    }
    return (path);
}