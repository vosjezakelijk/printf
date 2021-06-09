/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamatha <hsamatha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 18:16:43 by hsamatha          #+#    #+#             */
/*   Updated: 2021/06/09 14:28:53 by hsamatha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		write_u(t_flags *flags, int i, unsigned int u)
{
	i = 0;
	count_tmp(flags); //define flags
	flags->len = order_unsgn(u, 10); //counf actual length
	if (flags->precision == -1 && u == 0)
		flags->tmp++;
	if (flags->minus)
		i += putunbr(u); //left alignment 123 1
	if (flags->width || flags->minus)
		i += putchars(flags->tmp, flags->len, i, ' '); //__ 2 123__ 3
	else if (flags->zero || flags->precision)
		i += putchars(flags->tmp, flags->len, i, '0'); //000 4
	if ((flags->precision != -1 || u != 0) && (flags->minus == 0)) //__123 2 000123 4 123 5
		i += putunbr(u);
	return (i);
}

static int		write_u_precision(t_flags *flags, int i, unsigned int u)
{
	i = 0;
	count_tmp(flags);
	flags->len = order_unsgn(u, 10);
	if (flags->precision == -1 && u == 0)
		flags->tmp++;
	if (flags->precision > flags->len)
		flags->print_precision = flags->precision;
	else
		flags->print_precision = flags->len;
	i += putchars(flags->tmp, flags->print_precision, i, ' '); //___
	i += putchars(flags->precision, flags->len, i, '0'); //__00 000
	if (flags->precision != -1 || u != 0)
		i += putunbr(u);  //__123 12300 __000123
	return (i);
}

static int		write_u_min_precision(t_flags *flags, int i, unsigned int u)
{
	i = 0;
	flags->len = order_unsgn(u, 10);
	if (flags->precision == -1 && u == 0)
		flags->minus++;
	i += putchars(flags->precision, flags->len, i, '0'); //00 1
	if (flags->precision != -1 || u != 0) //00123 1 123 2
		i += putunbr(u);
	if (flags->precision > flags->len)
		flags->print_precision = flags->precision;
	else
		flags->print_precision = flags->len;
	i += putchars(flags->minus, flags->print_precision, i, ' '); //123___ 2 123 3
	return (i);
}

int				spec_u(unsigned int u, t_flags *flags, int count)
{
	if ((flags->zero && flags->precision) || (flags->width && flags->precision))
		count += write_u_precision(flags, count, u);
	else if (flags->minus && flags->precision)
		count += write_u_min_precision(flags, count, u);
	else if (check_t_flags(flags))
		count += write_u(flags, count, u);
	else
		count += putunbr(u); //just print if no other specification 
	return (count);
}
