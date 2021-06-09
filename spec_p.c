/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamatha <hsamatha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 18:16:12 by hsamatha          #+#    #+#             */
/*   Updated: 2021/06/09 14:28:44 by hsamatha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_ptr_precision(t_flags *flags,
			int i, unsigned long long int ptr)
{
	i = 0;
	count_tmp(flags);
	flags->len = order_ptr(ptr);
	if (flags->precision > flags->len)
		flags->print_precision = flags->precision;
	else
		flags->print_precision = flags->len;
	if (!ptr)
		flags->tmp++;
	if (flags->minus == 0)
		i += putchars(flags->tmp, (flags->len + 2), i, ' '); //___
	i += ft_putstr("0x"); //___0x 0x
	i += putchars(flags->precision, flags->len, i, '0');
	if (ptr || flags->precision > 0)
		i += puthex(ptr, 'x');
	if (flags->minus)
		i += putchars(flags->tmp, (flags->len + 2), i, ' '); // 0x123___
	return (i);
}

static int	write_ptr(t_flags *flags, int i, unsigned long long int ptr)
{
	i = 0;
	count_tmp(flags);
	flags->len = order_ptr(ptr);
	if (flags->minus) //left alignment
	{
		i += ft_putstr("0x");
		i += puthex(ptr, 'x'); //0x123
	}
	if (flags->width || flags->minus)
		i += putchars(flags->tmp, (flags->len + 2), i, ' '); //0x123__  ___
	else if (flags->precision || flags->zero)
	{
		i += ft_putstr("0x"); //0x0000
		i += putchars(flags->tmp, flags->len, i, '0');
	}
	if (flags->minus == 0)
	{
		if (flags->width)
			i += ft_putstr("0x");
		if (ptr || flags->precision >= 0)
			i += puthex(ptr, 'x');
	}
	return (i);
}

int			spec_ptr(unsigned long long int ptr, t_flags *flags, int count)
{
	if (!ptr)
	{
		flags->len = 1;
		ptr = 0;
	}
	if (flags->precision && (flags->width || flags->zero || flags->minus))
		count += write_ptr_precision(flags, count, ptr);
	else if (check_t_flags(flags))
		count += write_ptr(flags, count, ptr);
	else
	{
		count += ft_putstr("0x"); //print prefix
		count += puthex(ptr, 'x'); //just print if no other specification 
	}
	return (count);
}
