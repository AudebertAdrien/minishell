/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:16:06 by aaudeber          #+#    #+#             */
/*   Updated: 2023/02/19 15:14:08 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(const char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		t;

	t = 0;
	i = 0;
	if (!s)
		return (NULL);
	tab = (char **)ft_calloc((ft_count_words(s, c) + 1), sizeof(char *));
	if (!tab)
		return (NULL);
	while (s[i])
	{
		j = 0;
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			while (s[i + j] && s[i + j] != c)
				j++;
			tab[t++] = ft_substr(s, i, j);
		}
		i++;
	}
	tab[t] = NULL;
	return (tab);
}
