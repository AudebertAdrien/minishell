/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:26:29 by aaudeber          #+#    #+#             */
/*   Updated: 2023/02/12 18:15:05 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The  memmove()  function  copies n bytes from memory area src to 
	memory area dest.  The memory areas may overlap:
   	copying takes place as though the bytes in src are first copied into a
	temporary array that does not overlap  src or dest, 
	and the bytes are then copied from the temporary array to dest.

	RETURN VALUE
       	The memmove() function returns a pointer to dest.
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dst_cpy;
	char	*src_cpy;

	dst_cpy = (char *)dest;
	src_cpy = (char *)src;
	if (dest > src)
	{
		while (n--)
			dst_cpy[n] = src_cpy[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
