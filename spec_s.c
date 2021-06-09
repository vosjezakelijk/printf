/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamatha <hsamatha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 18:16:30 by hsamatha          #+#    #+#             */
/*   Updated: 2021/06/09 14:28:49 by hsamatha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_s_precision(t_flags *flags, int i, char *s)
{
	char *str;

	str = "(null)"; //for new entry
	count_tmp(flags); //define flags
	flags->len = ft_strlen(s); //find actual length
	if (flags->precision >= flags->len)
		flags->print_precision = flags->len; //adopt printable
	else
		flags->print_precision = flags->precision; //adopt printable
	if (flags->precision == -1)
		flags->tmp--;
	else if (s == str)
		flags->precision = 0;
	i += putchars(flags->tmp, flags->print_precision, i, ' '); //____hello
	while (flags->print_precision > 0)
	{
		i += ft_putchar(*s); //___hello
		s++;
		flags->print_precision--;
	}
	return (i);
}

static int	write_s_min_precision(t_flags *flags, int i, char *s)
{
	flags->len = ft_strlen(s);
	if (flags->precision >= flags->len)
		flags->print_precision = flags->len;
	else
		flags->print_precision = flags->precision;
	while (flags->print_precision > 0)
	{
		i += ft_putchar(*s); //left alignmnet start printing hello
		s++;
		flags->print_precision--;
	}
	if (flags->precision == -1)
		flags->minus--;
	if (flags->precision >= flags->len)
		flags->print_precision = flags->len; //define printable preciion
	else
		flags->print_precision = flags->precision;
	i += putchars(flags->minus, flags->print_precision, i, ' '); //hello___
	return (i);
}

static int	write_s(t_flags *flags, int i, char *s)
{
	i = 0;
	count_tmp(flags);
	flags->len = ft_strlen(s);
	if ((flags->precision == 0) && (flags->minus == 0))
	{
		if (flags->width)
			i += putchars(flags->tmp, flags->len, i, ' '); //__
		else if (flags->zero)
			i += putchars(flags->tmp, flags->len, i, '0'); //00
	}
	if ((flags->precision >= flags->len) || (flags->precision == 0))
		i += ft_putstr(s); //__hello hello 000hello
	else if (flags->precision < flags->len)
	{
		while (flags->precision > 0)
		{
			i += ft_putchar(*s); //print chars till precision is over hello world ---- hello
			s++;
			flags->precision--;
		}
	}
	if (flags->minus)
		i += putchars(flags->tmp, flags->len, i, ' ');
	return (i);
}

int			spec_s(char *s, t_flags *flags, int count)
{
	if (!s)
		s = "(null)";
	if ((flags->zero && flags->precision) || (flags->width && flags->precision))
		count += write_s_precision(flags, count, s);
	else if (flags->minus && flags->precision)
		count += write_s_min_precision(flags, count, s);
	else if (check_t_flags(flags))
		count += write_s(flags, count, s);
	else
		count += ft_putstr(s); //just print if no other specification 
	return (count);
}
