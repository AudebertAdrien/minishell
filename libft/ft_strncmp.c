/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 09:59:58 by aaudeber          #+#    #+#             */
/*   Updated: 2023/02/14 15:29:05 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION
   	The strcmp() function compares the two strings s1 and s2.  
	The locale is not taken into account (for a locale-aware 
	comparison, see strcoll(3)).  It returns an integer less than, equal to, 
	or greater than zero if s1 is  found,  respectively, to be less than, 
	to match, or be greater than s2.

	The strncmp() function is similar, except it compares only the first 
	(at most) n bytes of s1 and s2.

   	RETURN VALUE
   	The  strcmp()  and  strncmp()  functions  return an integer less than, equal 
	to, or greater than zero if s1 (or the first n bytes thereof) is found, 
	respectively, to be less than, to match, or be greater than s2.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && (s1[i] == s2[i]) && i < (n - 1))
	{
		if (s1[i] == s2[i])
			i++;
	}		
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
