/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamatha <hsamatha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 18:14:04 by hsamatha          #+#    #+#             */
/*   Updated: 2021/03/17 18:30:40 by hsamatha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_flags
{
	int			width; // positive width, with normal, move to the right
	int			minus; //width when align to the left //widthalign
	int			zero;//width through zero
	int			precision;
	int			len; //(actual length)
	int			print_precision; //precision to print
	int			tmp; // param that definds width (using width, precision)
}				t_flags;

int				ft_printf(const char *format, ...);
int				ft_execute(va_list args, const char **str);
void			default_flags(t_flags *flags);
void			ft_flag_parser(va_list args, const char **str, t_flags *flags);
int				ft_type_parser(va_list args,
					const char **str, t_flags *flags, int count);
int				def_digit(va_list args, const char **str);
void			flag_precision(va_list args, const char **str, t_flags *flags);
void			flag_zero(va_list args, const char **str, t_flags *flags);
void			flag_minus(va_list args, const char **str, t_flags *flags);
void			flag_width(va_list args, const char **str, t_flags *flags);
int				percent(t_flags *flags, int count);
int				spec_c(int c, t_flags *flags, int count);
int				spec_i_d(int n, t_flags *flags, int count);
int				spec_ptr(unsigned long long int ptr, t_flags *flags, int count);
int				spec_s(char *s, t_flags *flags, int count);
int				spec_u(unsigned int u, t_flags *flags, int count);
int				spec_upper_x(unsigned int x, t_flags *flags, int count);
int				spec_x(unsigned int x, t_flags *flags, int count);
int				ft_putchar(char c);
int				ft_putstr(char *str);
int				putchars(int a, int b, int count, char s);
size_t			ft_strlen(const char *str);
int				order_i_d(long int n);
int				order_ptr(unsigned long long int n);
int				order_unsgn(unsigned int n, unsigned int base);
int				putnbr(long int n);
int				putunbr(unsigned int n);
int				puthex(unsigned long long int n, int type);
int				check_t_flags(t_flags *flags);
void			count_tmp(t_flags *flags);
int				check_type(char c);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
int				ft_toupper(int c);

#endif
