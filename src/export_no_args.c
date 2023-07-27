/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_no_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:59:32 by mcreus            #+#    #+#             */
/*   Updated: 2023/07/27 13:03:55 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	return (i);
}

static int	compare(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	if (s1[i] == 0)
		return (1);
	if (s1[i] < s2[i])
		return (0);
	return (1);
}

static inline void	swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	sort(char **table)
{
	int	i;
	int	j;

	i = 0;
	while (table[i])
	{
		j = 0;
		while (table[j])
		{
			if (compare(table[i], table[j]) == 0)
			{
				swap(&(table[i]), &(table[j]));
				i--;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	print_export(char **envp)
{
	char	**table;
	int		tmp;
	int		n;

	if (!envp || !envp[0])
		return ;
	n = count(envp);
	table = malloc((n + 1) * sizeof(char *));
	table[n] = 0;
	tmp = n;
	while (tmp--)
		table[tmp] = envp[tmp];
	sort(table);
	n = 0;
	while (table[n])
	{
		printf("%s\n", table[n]);
		++n;
	}
	free(table);
}