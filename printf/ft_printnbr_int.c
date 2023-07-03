/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:22:49 by motoko            #+#    #+#             */
/*   Updated: 2023/03/07 13:32:22 by aaudeber         ###   ########.fr       */
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
