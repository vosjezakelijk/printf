/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamatha <hsamatha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 18:17:28 by hsamatha          #+#    #+#             */
/*   Updated: 2021/06/09 14:29:06 by hsamatha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		order_i_d(long int n)
{
	int	i;

	i = 1;
	if (n != 0)
	{
		if (n < 0)
		{
			n *= -1;
			i++;
		}
		while (n >= 10) //base decimal
		{
			n = n / 10;
			i++;
		}
	}
	return (i);
}

int		order_ptr(unsigned long long int n)
{
	int	i;

	i = 1;
	if (n != 0)
	{
		while (n >= 16) //base hex
		{
			n = n / 16;
			i++;
		}
	}
	return (i);
}

int		order_unsgn(unsigned int n, unsigned int base)
{
	int	i;

	i = 1;
	if (n != 0)
	{
		while (n >= base) //given base
		{
			n = n / base;
			i++;
		}
	}
	return (i);
}

int		ft_atoi(const char *str)
{
	long long	n;
	int			i;
	int			sign;

	sign = 1;
	n = 0;
	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = 10 * n + (str[i] - '0') * sign;
		i++;
		if (n < 0 && sign > 0)
			return (-1);
		if (n > 0 && sign < 0)
			return (0);
	}
	return (n);
}
