/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:43:01 by aaudeber          #+#    #+#             */
/*   Updated: 2023/05/06 15:47:02 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_printnbr_base(unsigned int nbr, char *base);
int		ft_printnbr_int(int n, int count);
int		ft_printnbr_unsigned(size_t n, int count);
int		ft_printnbr_ptr(unsigned long nbr);
int		ft_printchar(char c);
int		ft_printstr(const char *c);
size_t	ft_strlen(const char *str);
#endif
