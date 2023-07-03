/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:06:57 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/07 13:31:51 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	processes_format(va_list arg_lst, const char format)
{
	int	count;

	count = 0;
	if (format == '%')
		count += ft_printchar('%');
	if (format == 'i' || format == 'd')
		count += ft_printnbr_int(va_arg(arg_lst, int), 0);
	if (format == 'u')
		count += ft_printnbr_unsigned(va_arg(arg_lst, unsigned int), 0);
	if (format == 'c')
		count += ft_printchar(va_arg(arg_lst, int));
	if (format == 's')
		count += ft_printstr(va_arg(arg_lst, const char *));
	if (format == 'x')
		count += ft_printnbr_base(va_arg(arg_lst, unsigned int), "x");
	if (format == 'X')
		count += ft_printnbr_base(va_arg(arg_lst, unsigned int), "X");
	if (format == 'p')
		count += ft_printnbr_ptr(va_arg(arg_lst, unsigned long));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	arg_lst;

	va_start(arg_lst, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += processes_format(arg_lst, format[i + 1]);
			i++;
		}
		else
			count += ft_printchar(format[i]);
		i++;
	}
	va_end(arg_lst);
	return (count);
}
