/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus & aaudeber <mcreus@student.42per    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 09:56:49 by mcreus & aa       #+#    #+#             */
/*   Updated: 2023/07/03 18:51:31 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/types.h>
# include <dirent.h>

# include "libft.h"
# include "ft_printf.h"

typedef struct s_var
{
	char	**env;
	char	*pwd;
}	t_var;

typedef struct s_path
{
	char	*path;
	char	*old_path;
	char	*new_path;
}	t_path;

int		echo(char **tab);
int		parse_readline(char *str);
int		find_cmd(char **tab);

#endif
