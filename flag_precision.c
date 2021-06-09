/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamatha <hsamatha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:33:56 by hsamatha          #+#    #+#             */
/*   Updated: 2021/06/09 14:28:00 by hsamatha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_precision(va_list args, const char **str, t_flags *flags) // if .
{
	flags->precision = def_digit(args, &(*str)); //convert to int, or if * -- give a param to va_arg
	if (flags->precision == 0) //case if precision is 0
		flags->precision = -1; //change to standart -1 
	else if (flags->precision < 0) //if was unchanged from -1
		flags->precision = 0; 
}
