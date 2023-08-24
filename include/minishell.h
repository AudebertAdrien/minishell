/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 09:56:49 by mcreus & aa       #+#    #+#             */
/*   Updated: 2023/08/24 17:26:43 by motoko           ###   ########.fr       */
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
# include <fcntl.h>
# include <stddef.h>

# include "libft.h"
# include "ft_printf.h"

typedef struct s_vars
{
	char	**envcpy;
	char	**cmd;
	char	**file_in;
	char	**file_out;
	char	**type_in;
	char	**type_out;
}	t_vars;

typedef struct s_list
{
	char	**cmd;
	char	**args;
	char	**file_in;
	char	**file_out;
	char	**type_in;
	char	**type_out;
	struct	s_list *next;
}		t_list;

extern t_vars vars;

char	*display_prompt(char **env);
char	*ft_get_env(char **env, char *needle);
char	*ft_get_path(char *pwd_line, char *user_line);
char	*grep_workstation(char *session_line);
char	*get_relative_path(char *pwd, char *user);
char	*free_and_join(char *s1, char *s2);

int	ft_len_tab(char **tab);
int	**ft_envcpy(char **env);
int	parse_readline(char *str);
int	find_cmd(char **tab);
int	echo(char **tab, char **env);
int	ft_cd(char **args, char **env);
int	ft_pwd(char **args);
int	ft_get_index(char **env, char *needle);
int	ft_cmp_char(char c, char *str);
int	free_tabs(char **env);
int	redirection(void);

t_list	*ft_lstnew();
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_add_el_to_tab(char **tab, char *s);
void	ft_env(char **env);
void	export(char **args, char **envp);
void	print_export(char **envp);
void	ft_unset(char **args);
void	stats(t_list **lst);
#endif
