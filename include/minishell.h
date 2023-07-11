/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 09:56:49 by mcreus & aa       #+#    #+#             */
/*   Updated: 2023/07/11 11:46:11 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#ifdef __APPLE__
# define APPLE 1
#else
# define APPLE 0
#endif

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
	char 	*pwd;
	int		exit;
	char	*str;
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
	struct s_char	*next;
	struct s_char	*previous;
}	t_char;



char	*display_prompt(char **env);
int		parse_readline(char *str, char **env);
int		find_cmd(char **tab, char **env);
int		echo(char **tab);
int		ft_cd(char **args, char **env);
char	*ft_pwd(char **args, char **env);

#endif
