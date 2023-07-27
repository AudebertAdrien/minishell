/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:02:13 by aaudeber          #+#    #+#             */
/*   Updated: 2023/07/27 13:57:45 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_double_quote(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	if (str[0] == '"' && str[len - 1] == '"')
		return (1);
	return (0);
}

int	echo(char **tab, char **env)
{
	int	i;
	char	*str;

	i = 1;
	while (tab[i])
	{
		if (is_double_quote(tab[i]))
		{
//			printf("USER %s\n", ft_get_env(env, "USER"));
//			printf("1 %s\n", ft_substr(tab[i], 1, ft_strlen(tab[i]) - 2));
//			printf("2 %s\n", getenv(ft_substr(tab[i], 1, ft_strlen(tab[i] - 2)) ));
			str =  ft_substr(tab[i], 1, ft_strlen(tab[i]) - 2);
			printf("2 %s\n", getenv(str));

		}
		//ft_putstr_fd(tab[i], 1);
		if (ft_strncmp(tab[1], "-n", 3))
			ft_putchar_fd('\n', 1);
		i++;
	}
	return (0);
}
