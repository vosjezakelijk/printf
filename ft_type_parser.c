/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamatha <hsamatha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:34:59 by hsamatha          #+#    #+#             */
/*   Updated: 2021/03/05 18:46:00 by hsamatha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type_parser(va_list args,
			const char **str, t_flags *flags, int count)
{
	count = 0;
	if (**str == 'c')
		count += spec_c(va_arg(args, int), flags, count);
	else if (**str == 'd' || **str == 'i')
		count += spec_i_d(va_arg(args, int), flags, count);
	else if (**str == 's')
		count += spec_s(va_arg(args, char *), flags, count);
	else if (**str == 'u')
		count += spec_u((unsigned int)va_arg(args, unsigned int), flags, count);
	else if (**str == 'x')
		count += spec_x(va_arg(args, unsigned int), flags, count);
	else if (**str == 'X')
		count += spec_upper_x(va_arg(args, unsigned int), flags, count);
	else if (**str == 'p')
		count += spec_ptr(va_arg(args, unsigned long long), flags, count);
	else if (**str == '%')
		count += percent(flags, count);
	return (count);
}
