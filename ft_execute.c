/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamatha <hsamatha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:34:36 by hsamatha          #+#    #+#             */
/*   Updated: 2021/06/09 14:28:09 by hsamatha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_execute(va_list args, const char **str)
{
	int		count;
	t_flags	flags;

	count = 0;
	while (**str)
	{
		if (**str == '%') // signal to start defining format
		{
			(*str)++;
			if (**str == '\0') //make sure that the line is not over
				return (0);
			default_flags(&flags);
			ft_flag_parser(args, &(*str), &flags); 
			count += ft_type_parser(args, &(*str), &flags, count);
		}
		else
			count += ft_putchar(**str); //just print the content of the line out
		(*str)++;
	}
	return (count);
}
