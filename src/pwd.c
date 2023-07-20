/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:17:11 by mcreus            #+#    #+#             */
/*   Updated: 2023/07/20 11:07:36 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_pwd(char **args)
{
	char *path;

	(void)args;
	path = getcwd(NULL, 0);
	if (path == NULL)
		return (1);
	ft_putendl_fd(path, 1);
	free(path);
	return (0);
}
