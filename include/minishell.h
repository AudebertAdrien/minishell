/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus & aaudeber <mcreus@student.42per    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 09:56:49 by mcreus & aa       #+#    #+#             */
/*   Updated: 2023/07/03 17:47:15 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

# include "libft.h"
# include "ft_printf.h"

typedef struct s_env
{
	char	**env;
}	t_env;

int		echo();
int		parse_readline(char *str);
int		find_cmd(char **tab);

#endif
