/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 09:56:49 by mcreus & aa       #+#    #+#             */
/*   Updated: 2023/08/04 10:53:17 by mcreus           ###   ########.fr       */
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
# include <stdlib.h>
# include <errno.h>
# include <dirent.h>
# include <string.h>

# include "libft.h"
# include "ft_printf.h"

typedef struct s_var
{
	char	**env;
	char 	*pwd;
	int		exit_status;
	char	*str;
	
}	t_var;

//t_var	g_var;

typedef struct s_path
{
	char	**path;
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

int		parse_readline(char *str, char **env);
int		find_cmd(char **tab, char **env);
int		echo(char **tab);
int		ft_cd(char **args, char **env);
char	*display_prompt(char **env);
char	*ft_get_env(char **env, char *needle);
char	*ft_get_path(char *pwd_line, char *user_line);
char	*grep_workstation(char *session_line);
char	*get_relative_path(char *pwd, char *user);
char	*free_and_join(char *s1, char *s2);
void	export(char **args, char ***envp);
int		dup_table(char ***new_env, int *i, int pos, char **envp);
void	export_pwd(char ***envp, char *newpwd);
void	print_export(char **envp);
int	dup_table(char ***new_env, int *i, int pos, char **envp);
void	add_table(char ***new_env, char *add, int *i, char **envp);
int	dup_add_table_short(char ***new_env, char *add, int *i, char **envp);

#endif
