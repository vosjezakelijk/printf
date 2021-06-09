/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_upper_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamatha <hsamatha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 18:16:56 by hsamatha          #+#    #+#             */
/*   Updated: 2021/06/09 14:28:56 by hsamatha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		write_upper_hex_precision(t_flags *flags, int i, unsigned int x)
{
	i = 0;
	count_tmp(flags);
	flags->len = order_unsgn(x, 16);
	if (flags->precision > flags->len)
		flags->print_precision = flags->precision;
	else
		flags->print_precision = flags->len;
	if (flags->precision == -1 && x == 0)
		flags->tmp++;
	if (flags->minus == 0)
		i += putchars(flags->tmp, flags->print_precision, i, ' ');
	i += putchars(flags->precision, flags->len, i, '0');
	if (flags->precision != -1 || x != 0)
		i += puthex(x, 'X');
	if (flags->minus)
		i += putchars(flags->tmp, flags->print_precision, i, ' ');
	return (i);
}

static int		write_upper_hex(t_flags *flags, int i, unsigned int x)
{
	i = 0;
	count_tmp(flags);
	flags->len = order_unsgn(x, 16);
	if (flags->precision == -1 && x == 0)
		flags->tmp++;
	if (flags->minus && (flags->precision != -1 || x != 0))
		i += puthex(x, 'X'); //123 1
	if (flags->width || flags->minus)
		i += putchars(flags->tmp, flags->len, i, ' '); //123__ 1 __ 2
	else if (flags->zero || flags->precision)
		i += putchars(flags->tmp, flags->len, i, '0'); //000 3 123000 4
	if ((flags->precision != -1 || x != 0) && (flags->minus == 0))
		i += puthex(x, 'X'); //__123 2 000123 3
	return (i);
}

int				spec_upper_x(unsigned int x, t_flags *flags, int count)
{
	if ((flags->width || flags->zero || flags->minus) && flags->precision)
		count += write_upper_hex_precision(flags, count, x);
	else if (check_t_flags(flags))
		count += write_upper_hex(flags, count, x);
	else
		count += puthex(x, 'X'); //just print if no other specification 
	return (count);
}
