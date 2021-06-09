/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamatha <hsamatha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 18:17:18 by hsamatha          #+#    #+#             */
/*   Updated: 2021/06/09 14:29:03 by hsamatha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int		ft_putstr(char *str)
{
	int i;

	i = 0;
	if (str[i])
	{
		while (str[i])
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	return (i);
}

int		putchars(int a, int b, int count, char s)
{
	count = 0;
	while ((a - b) > 0)
	{
		count += ft_putchar(s);
		a--;
	}
	return (count);
}

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
