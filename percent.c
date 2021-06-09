/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamatha <hsamatha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 18:15:02 by hsamatha          #+#    #+#             */
/*   Updated: 2021/03/17 18:46:27 by hsamatha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		percent(t_flags *flags, int count) // no prscision for a char
{
	count = 0;
	count_tmp(flags);
	if (flags->minus) // we need left alignment -- print first %__1
		count += ft_putchar('%');
	while ((flags->tmp - 1) > 0) //while width is available, 1 char is used by %
	{
		if (flags->zero) //will work only if no minus ) 00%2
			count += ft_putchar('0');
		else if (flags->width || flags->minus) //when need to add chars till width is full 
			count += ft_putchar(' '); //%__,1 __%3
		flags->tmp--;
	}
	if (flags->minus == 0) // else if no minus , right alignment, print the last __%3
		count += ft_putchar('%');
	return (count);
}
