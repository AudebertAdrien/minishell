/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 09:56:49 by mcreus & aa       #+#    #+#             */
/*   Updated: 2023/08/03 12:02:36 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#ifdef __APPLE__
# define APPLE 1
#else
# define APPLE 0
#endif
# define IDLE_PROMT "<minishell>"

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

# include "libft.h"

typedef struct s_var
{
	char	**env;
	char	**args;
	char 	*pwd;
	int		exit_status;
	char	*str;
	int		parent_pid;
}	t_var;

//t_var	g_var;

typedef struct s_env
{
	char			*var;
	char			*value;
	struct s_env	*next;
}	t_env;

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
int		echo(char **tab, char **env);
int		ft_cd(char **args, char **env);
int		find_cmd(char **tab, char **env);
int		ft_cd(char **args, char **env);
char	*display_prompt(char **env);
int		parse_readline(char *str, char **env);
int		find_cmd(char **tab, char **env);
int		ft_cd(char **tab, char **env);
int		ft_pwd(char **args);
int		parse_readline(char *str, char **env);
int		find_cmd(char **tab, char **env);
int		ft_cd(char **tab, char **env);
int		ft_pwd(char **args);
char	*ft_get_env(char **env, char *needle);
int		ft_get_index(char **env, char *needle);
char	*ft_get_path(char *pwd_line, char *user_line);
char	*grep_workstation(char *session_line);
char	*get_relative_path(char *pwd, char *user);
void	ft_env(char **env);
int		cmp_char(char c, char *str);
char	**ft_envcpy(char **env);
char	*free_and_join(char *s1, char *s2);
void	export(char **args, char ***envp);
int		dup_table(char ***new_env, int *i, int pos, char **envp);
void	export_pwd(char ***envp, char *newpwd);
void	print_export(char **envp);
int		dup_table(char ***new_env, int *i, int pos, char **envp);
void	add_table(char ***new_env, char *add, int *i, char **envp);
int		dup_add_table_short(char ***new_env, char *add, int *i, char **envp);
void	ft_tabfree(char **tab);
char	**cmd_exit(char **args, char **env);

typedef struct s_cmd {
	char	*cmd;
	char	**args;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_file {
	char *file;
	char *end_of_file;
	int		flag;
}	t_file;

typedef struct s_line {
	t_file	input;
	t_file	output;
	t_cmd	*cmd;
	int		loop;
}	t_line;


#endif