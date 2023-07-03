/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 13:08:46 by aaudeber          #+#    #+#             */
/*   Updated: 2023/02/12 18:11:23 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The  memcmp()  function compares the first n bytes 
	(each interpreted as unsigned char) of the memory areas s1 and s2.

	RETURN VALUE :
       	The memcmp() function returns an integer less than, equal to, or 
	greater than zero if the first n bytes of s1  is found, respectively, 
	to be less than, to match, or be greater than the first n bytes of s2.
	For  a nonzero return value, the sign is determined by the sign of 
	the difference between the first pair of bytes
      	(interpreted as unsigned char) that differ in s1 and s2.
	If n is zero, the return value is zero.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*mem1;
	unsigned char	*mem2;
	size_t			i;

	i = 0;
	mem1 = (unsigned char *)s1;
	mem2 = (unsigned char *)s2;
	while (i < n)
	{
		if (mem1[i] != mem2[i])
			return (mem1[i] - mem2[i]);
		i++;
	}
	return (0);
}
