/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:36:51 by aaudeber          #+#    #+#             */
/*   Updated: 2023/02/15 14:01:13 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The  memcpy()  function copies n bytes from memory area src to 
	memory area dest.  The memory areas must not overlap.

	RETURN VALUE
       	The memcpy() function returns a pointer to dest.
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dst_cpy;
	char	*src_cpy;

	if (!dest && !src)
		return (dest);
	src_cpy = (char *)src;
	dst_cpy = (char *)dest;
	while (n--)
		*dst_cpy++ = *src_cpy++;
	return (dest);
}
