/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_ptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:45:34 by motoko            #+#    #+#             */
/*   Updated: 2023/03/07 13:48:00 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_processes_base(unsigned long nbr, char *base, int count)
{
	unsigned long		base_l;

	base_l = ft_strlen(base);
	if (nbr >= base_l)
		count = ft_processes_base(nbr / base_l, base, count);
	count += ft_printchar(base[nbr % base_l]);
	return (count);
}

int	ft_printnbr_ptr(unsigned long nbr)
{	
	int	count;

	count = 0;
	if (nbr == 0)
		return (ft_printstr("(nil)"));
	else
	{
		count += ft_printstr("0x");
		count += ft_processes_base(nbr, "0123456789abcdef", 0);
	}
	return (count);
}
