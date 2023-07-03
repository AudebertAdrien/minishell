/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:20:14 by aaudeber          #+#    #+#             */
/*   Updated: 2023/02/17 18:21:08 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION
	The strlcat() functions concatenate strings. 
	Strlcat() take the full size of the buffer (not just the length) 
	and guarantee to NUL-terminate the result (as long as size is larger 
	than 0 or, in the case of strlcat(), as long as there is at least 
	one byte free in dst)
	Note that a byte for the NUL should be included in size
	The strlcat() function appends the NUL-terminated string src to 
	the end of dst.  It will append at most size - strlen(dst) - 1 bytes, 
	NUL-terminating the result.

	RETURN VALUES
	The strlcpy() and strlcat() functions return the total length of the 
	string they tried to create.
	For strlcat() that means the initial length of dst plus the length of src.
*/

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	dst_size;
	size_t	src_size;

	if (!size && !dst)
		return (0);
	i = 0;
	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (!size)
		return (src_size);
	if (size < dst_size)
		return (size + src_size);
	while (src[i] && (i + dst_size) < (size - 1))
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	dst[dst_size + i] = '\0';
	return (dst_size + src_size);
}
