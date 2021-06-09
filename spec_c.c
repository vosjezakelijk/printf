/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamatha <hsamatha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 18:15:16 by hsamatha          #+#    #+#             */
/*   Updated: 2021/06/09 14:28:36 by hsamatha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		spec_c(int c, t_flags *flags, int count) // no precision for char
{
	count = 0;
	count_tmp(flags);  //define flags
	if (flags->minus)
		count += ft_putchar(c); //c__1
	while ((flags->tmp - 1) > 0)
	{
		if (flags->zero) //  no precision for char, othewise would be flag->presicion check, minus negate zero, only right alignmmnet
			count += ft_putchar('0');  //00c2
		else if (flags->width || flags->minus)
			count += ft_putchar(' '); //__c,3 c__1
		flags->tmp--;
	}
	if (flags->minus == 0)
		count += ft_putchar(c); //__c3
	return (count);
}
