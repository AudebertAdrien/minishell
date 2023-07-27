/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:22:49 by motoko            #+#    #+#             */
/*   Updated: 2023/07/27 17:50:31 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr_int(int n, int count)
{
	unsigned int	s;

	if (n < 0)
	{
		count += ft_printchar('-');
		s = n * -1;
	}
	else
		s = n;
	if (s > 9)
		count = ft_printnbr_int(s / 10, count);
	count += ft_printchar(s % 10 + 48);
	return (count);
}
