/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_minus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamatha <hsamatha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:33:41 by hsamatha          #+#    #+#             */
/*   Updated: 2021/06/09 14:27:57 by hsamatha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_minus(va_list args, const char **str, t_flags *flags) //with minus we need to move content to the left, normally to the right
{
	if (flags->zero != -1) //if zero exists -- negate zero  (flags->zero = 1) (flags->zero)  // minus >>>>> zero
		(*str)++; //move to the nextchar, do nothing with zero, negate zero
	if (**str != '.') //if doesn't defines presicion -- check width
	{
		if ((**str >= '0' && **str <= '9') || **str == '*') //identifiers of the width with alignment
		{
			flags->minus = def_digit(args, &(*str)); // if digits convert to int, if * -- given to va_arg -- param as definit of WIDTH
			if (flags->minus < 0) //if width is negative, proceed using minus (width alignment)
				flags->minus = -flags->minus; //not planning to work with negative numbers, convert to a positive
		}
		else
			(*str)--;
	}
	else
		(*str)--;
}
