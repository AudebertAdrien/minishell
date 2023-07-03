/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_unsigned.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:22:49 by motoko            #+#    #+#             */
/*   Updated: 2023/03/06 17:12:57 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr_unsigned(size_t n, int count)
{
	if (n > 9)
		count = ft_printnbr_unsigned(n / 10, count);
	count += ft_printchar(n % 10 + 48);
	return (count);
}
