/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:22:49 by motoko            #+#    #+#             */
/*   Updated: 2023/02/13 19:31:07 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	s;

	s = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		s = n * -1;
	}
	else
		s = n;
	if (s > 9)
		ft_putnbr_fd(s / 10, fd);
	ft_putchar_fd(s % 10 + 48, fd);
}
