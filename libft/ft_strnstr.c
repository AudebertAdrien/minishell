/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:54:31 by aaudeber          #+#    #+#             */
/*   Updated: 2023/02/26 19:07:28 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION
	The strnstr() function locates the first occurrence of the 
	null-terminated string little in the string big, 
	where not more than len characters are searched.
	Characters that appear after a ‘\0’ character are not
     	searched.  Since the strnstr() function 
	is a FreeBSD specific API, 
	it should only be used when portability is not a concern.

	RETURN VALUES
     	If little is an empty string, big is returned; if little occurs 
	nowhere in big, NULL is returned; otherwise a
     	pointer to the first character of the first 
	occurrence of little is returned.
*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*little)
		return ((char *)big);
	if (!*big)
		return (0);
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] && little[j] == big[i + j] && (i + j) < len)
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}
