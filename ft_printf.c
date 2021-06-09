/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamatha <hsamatha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 18:12:54 by hsamatha          #+#    #+#             */
/*   Updated: 2021/06/09 14:28:17 by hsamatha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...) //we define only the fisrt arg that we kno, there might be a lot of various args after, or there might be NONE
{
	va_list args; /various argumnets list
	int		count; //count what char of the line we are on now

	count = 0;
	va_start(args, format);
	count += ft_execute(args, &format); // can be iterative +=ft_execute, can convert to const char to char but works without extra work, just nicer <3
	va_end(args);
	return (count);
}
