/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:45:34 by motoko            #+#    #+#             */
/*   Updated: 2023/03/07 14:13:11 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_processes_base(unsigned int nbr, char *base, int count)
{
	unsigned int		base_l;

	base_l = ft_strlen(base);
	if (nbr >= base_l)
		count = ft_processes_base(nbr / base_l, base, count);
	count += ft_printchar(base[nbr % base_l]);
	return (count);
}

int	ft_printnbr_base(unsigned int nbr, char *base)
{
	int	count;

	count = 0;
	if (*base == 'x')
		count = ft_processes_base(nbr, "0123456789abcdef", count);
	if (*base == 'X')
		count = ft_processes_base(nbr, "0123456789ABCDEF", count);
	return (count);
}
