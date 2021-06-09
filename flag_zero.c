/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_zero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamatha <hsamatha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:34:20 by hsamatha          #+#    #+#             */
/*   Updated: 2021/06/09 14:28:05 by hsamatha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_zero(va_list args, const char **str, t_flags *flags)
{
	while (**str == '0') //if a few zeros pass zeros
		(*str)++;
	if (**str == '-') //conflict with zero
	{
		(*str)++;// pass minus minus >>>>> zero, negatezero
		if ((**str >= '0' && **str <= '9') || **str == '*')
			flags->minus = def_digit(args, &(*str));//define width through minus//width left alignment
		else
			(*str)--;
	}
	else if ((**str >= '0' && **str <= '9') || **str == '*') //definitions of positive width
	{
		flags->zero = def_digit(args, &(*str));//define width through zero positive
		if (flags->zero < 0) // if width is negative then define through minus-negative width with alignment
		{
			flags->minus = -flags->zero;//define width through minus
			flags->zero = 0;
		}
	}
	else
		(*str)--;
}
