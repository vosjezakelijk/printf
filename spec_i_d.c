/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_i_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamatha <hsamatha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 18:15:32 by hsamatha          #+#    #+#             */
/*   Updated: 2021/06/09 14:28:39 by hsamatha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_int_min_precision(t_flags *flags, int i, int n)
{
	i = 0;
	count_tmp(flags);  //define flags
	flags->len = order_i_d(n); //def actual length
	if (n < 0 && n > -2147483648) //with a negative nbr
	{
		flags->precision++;
		i += ft_putchar('-'); //print -
		n *= -1;
	}
	else if (flags->precision == -1 && n == 0) //if nbrs is zero
		flags->tmp++;
	if (flags->precision > flags->len)
		flags->print_precision = flags->precision;  //def print presicion
	else
		flags->print_precision = flags->len;
	i += putchars(flags->precision, flags->len, i, '0'); //000
	if (flags->precision != -1 || n != 0) //000123 123
		i += putnbr(n);
	i += putchars(flags->tmp, flags->print_precision, i, ' '); //123___
	return (i);
}

static int	write_int_precision(t_flags *flags, int i, int n)
{
	i = 0;
	count_tmp(flags);
	flags->len = order_i_d(n);
	if (flags->precision > flags->len) //if presicion is bigger that actual lenght
		flags->print_precision = flags->precision; //print size of precision
	else
		flags->print_precision = flags->len; //otherise print actual length
	if ((flags->precision == -1 && n == 0) && (flags->zero == 0)) //when number is 0
		flags->tmp++;
	else if ((flags->precision < flags->len && n == 0)) //when number is 0
		flags->tmp++;
	else if ((flags->precision >= flags->len) && n < 0)  //when number is negative
		flags->tmp--;
	i += putchars(flags->tmp, flags->print_precision, i, ' '); //fill with spaces ___
	if (n < 0 && n > -2147483648) //when number is negative
	{
		i += ft_putchar('-'); //print -
		n *= -1; //convert to a positive
		flags->len--;
	}
	i += putchars(flags->precision, flags->len, i, '0'); 
	if (flags->precision != -1 || n != 0)
		i += putnbr(n);
	return (i);
}

static int	write_int(t_flags *flags, int i, int n)
{
	i = 0;
	count_tmp(flags); //define the actual width
	flags->len = order_i_d(n); //find actual length
	if ((flags->width == 0) && (n < 0 && n > -2147483648)) //if a negative number
	{
		i += ft_putchar('-'); //print minus // -
		n *= -1; //work with a positive number
		if (flags->precision)
			flags->tmp++;
	}
	if (flags->minus) //if need to be aligned left, start print the number //123
		i += putnbr(n);
	while ((flags->tmp - flags->len) > 0) //compare actual width and actual length
	{
		if (flags->precision || flags->zero) //for int check for precision and zero
			i += ft_putchar('0'); // 123000
		else if (flags->width || flags->minus) //-123___ 123___ ___123
			i += ft_putchar(' ');
		flags->tmp--;
	}
	if ((flags->minus == 0) && (flags->precision != -1 || n != 0)) // __123 //excl if no precision or nbr is zero
		i += putnbr(n);
	return (i);
}

int			spec_i_d(int n, t_flags *flags, int count)
{
	count = 0;
	if (flags->precision && flags->minus) //cases with alignment to left, negative width left alignment
		count += write_int_min_precision(flags, count, n);
	else if ((flags->precision && flags->width) //cases without alignment to left, positive width, right normal alignment
				|| (flags->precision && flags->zero))
		count += write_int_precision(flags, count, n);
	else if (check_t_flags(flags))
		count += write_int(flags, count, n);
	else
		count += putnbr(n);
	return (count);
}
