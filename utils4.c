/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamatha <hsamatha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:56:45 by hsamatha          #+#    #+#             */
/*   Updated: 2021/06/09 14:29:13 by hsamatha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	default_flags(t_flags *flags) //initialize
{
	flags->width = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->precision = 0;
	flags->len = 0;
	flags->print_precision = 0;
	flags->tmp = 0;
}

int		check_t_flags(t_flags *flags)
{
	if (flags->width || flags->minus || flags->zero || flags->precision)
		return (1);
	return (0);
}

int		check_type(char c)
{
	if ((c == '%') || (c == 'd') || (c == 'i') || (c == 'c') || (c == 's')
				|| (c == 'x') || (c == 'X') || (c == 'p') || (c == 'u'))
		return (1);
	return (0);
}

void	count_tmp(t_flags *flags) //define the most important feature for width
{
	if (flags->width) //positve width
		flags->tmp = flags->width; 
	else if (flags->zero) //positive width out zeros
		flags->tmp = flags->zero;
	else if (flags->minus) //width negative with alignment
		flags->tmp = flags->minus;
	else if (flags->precision) //positive width through precision
		flags->tmp = flags->precision;
}

int		def_digit(va_list args, const char **str)
{
	int		n;

	n = 0;
	if (ft_isdigit(**str))
	{
		n = ft_atoi(*str); //convert from char to int 
		while (ft_isdigit(*(*str + 1))) //check that the next char is a digit too
			(*str)++; // and only then increment
	}
	else if (**str == '*') //if defined not by digit but by * in a string
		n = va_arg(args, int); //give int
	return (n);
}
