/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 09:56:49 by mcreus & aa       #+#    #+#             */
/*   Updated: 2023/07/04 15:28:33 by mcreus           ###   ########.fr       */
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
	int		exit;
	char	*str;
	t_path	*pwd;
	t_char	*ch;
}	t_var;

typedef struct s_path
{
	char	*path;
	char	*old_path;
	char	*new_path;
}	t_path;

typedef struct s_char
{
	char	*ptr;
	char	type;
	char	*specific;
	struct s_char	*next;
}	t_char;


char	*display_prompt(char **env);
int		parse_readline(char *str);
int		find_cmd(char **tab);
int		echo(char **tab);

#endif
> doit rediriger la sortie