/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamatha <hsamatha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 18:17:37 by hsamatha          #+#    #+#             */
/*   Updated: 2021/06/09 14:29:09 by hsamatha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		putnbr(long int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		i += ft_putstr("-2147483648");
	if (n < 0 && n > -2147483648)
	{
		i += ft_putchar('-');
		n *= -1;
	}
	if (n < 10 && n > -2147483648)
	{
		i += ft_putchar(n + 48);
	}
	else if (n > 9)
	{
		i += putnbr(n / 10);
		i += putnbr(n % 10);
	}
	return (i);
}

int		putunbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i += ft_putchar('0');
	else if (n > 9)
	{
		i += putunbr(n / 10);
		i += putunbr(n % 10);
	}
	else if (n < 10)
	{
		i += ft_putchar(n + 48);
	}
	return (i);
}

int		puthex(unsigned long long int n, int type)
{
	int i;

	i = 0;
	if (n == 0)
		i += ft_putchar('0');
	else if (n >= 16)
	{
		i += puthex(n / 16, type);
		i += puthex(n % 16, type);
	}
	else if (n < 10)
	{
		i += ft_putchar(n + '0');
	}
	else if (n > 9)
	{
		if (type == 'x')
			i += ft_putchar(n + 87);
		else if (type == 'X')
			i += ft_putchar(ft_toupper(n + 87));
	}
	return (i);
}

int		ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (c - 32);
	}
	return (c);
}
