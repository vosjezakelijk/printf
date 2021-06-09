/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamatha <hsamatha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:34:49 by hsamatha          #+#    #+#             */
/*   Updated: 2021/06/09 14:28:13 by hsamatha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_parser(va_list args, const char **str, t_flags *flags)
{
	while (!(check_type(**str))) //check the flags only, before specificators(d, i, c) start
	{
		if ((((**str >= '0' && **str <= '9') && **str != '0')) || **str == '*')  //check if digit or a star --> then define width
			flag_width(args, &(*str), flags);
		else if (**str == '-')
			flag_minus(args, &(*str), flags); //define WIDTH width alignment, through param minus
		else if (**str == '0')
		{
			(*str)++;
			if (check_type(**str)) //if spec start immediately -- break
				break ;
			flag_zero(args, &(*str), flags);
		}
		else if (**str == '.')
		{
			flags->precision = -1; //change position form 0 to -1 //suggest to delete the line
			(*str)++;
			if (check_type(**str)) //if spec start immediately -- break
				break ;
			flag_precision(args, &(*str), flags);
		}
		(*str)++;
	}
}
