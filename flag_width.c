/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamatha <hsamatha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:34:07 by hsamatha          #+#    #+#             */
/*   Updated: 2021/03/17 18:19:35 by hsamatha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_width(va_list args, const char **str, t_flags *flags)
{
	flags->width = def_digit(args, &(*str)); //define through width positive
	if (flags->width < 0) //if negative
	{
		flags->minus = -flags->width; //define through minus,(width+alignment), convert to positive
		flags->width = 0; // not usuing positive width
	}
}
