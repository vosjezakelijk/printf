/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamatha <hsamatha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 18:17:07 by hsamatha          #+#    #+#             */
/*   Updated: 2021/06/09 14:29:00 by hsamatha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		write_upper_x(t_flags *flags, int i, unsigned int x)
{
	i = 0;
	count_tmp(flags); //define flags
	flags->len = order_unsgn(x, 16); //count actual legnth
	if (flags->precision == -1 && x == 0)
		flags->tmp++;
	if ((flags->precision != -1 || x != 0) && flags->minus)
		i += puthex(x, 'x');
	if (flags->minus || flags->width)
		i += putchars(flags->tmp, flags->len, i, ' ');
	else if (flags->zero || flags->precision)
		i += putchars(flags->tmp, flags->len, i, '0');
	if ((flags->precision != -1 || x != 0) && (flags->minus == 0))
		i += puthex(x, 'x');
	return (i);
}

static int		write_upper_x_precision(t_flags *flags, int i, unsigned int x)
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
		i += puthex(x, 'x');
	if (flags->minus)
		i += putchars(flags->tmp, flags->print_precision, i, ' ');
	return (i);
}

int				spec_x(unsigned int x, t_flags *flags, int count)
{
	if ((flags->width || flags->zero || flags->minus) && flags->precision)
		count += write_upper_x_precision(flags, count, x);
	else if (check_t_flags(flags))
		count += write_upper_x(flags, count, x);
	else
		count += puthex(x, 'x'); //just print if no other specification 
	return (count);
}
