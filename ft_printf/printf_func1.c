/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_func1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 17:54:30 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/01/21 13:56:33 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_int(long num, t_flag flag)
{
	int i;

	i = 0;
	if (num == 0 && flag.dot == 1 && flag.precision == 0)
	{
		while (i++ < flag.width)
			write(1, " ", 1);
		return (flag.width);
	}
	else if (flag.width > 0 && flag.dot == 1)
		return (ft_putnbr_prewidth(num, flag));
	else if (flag.width > 0 && flag.zero == 0)
		return (ft_putnbr_width(num, flag));
	else if (flag.width > 0 && flag.zero == 1 && flag.neg == 1)
		return (ft_putnbr_width(num, flag));
	else if (flag.dot == 1 || (flag.width > 0 && flag.zero == 1))
		return (ft_putnbr_pre(num, flag));
	else
		return (ft_putnbr(num));
}

int		put_char(char c, t_flag flag)
{
	if (flag.width > 0 && flag.neg == 1)
		return (ft_putchar_minwidth(c, flag.width));
	else if (flag.width > 0 && flag.zero == 1)
		return (ft_putchar_zerowidth(c, flag.width));
	else if (flag.width > 0)
		return (ft_putchar_width(c, flag.width));
	else
		return (ft_putchar(c));
}

int		put_str(char *str, t_flag flag)
{
	if (str == NULL)
	{
		if (flag.width > 0 && flag.dot == 1)
			return (ft_putstr_prewidth("(null)", flag));
		else if (flag.width > 0)
			return (ft_putstr_width("(null)", flag));
		else if (flag.dot == 1)
			return (ft_putstr_pre("(null)", flag.precision));
		else
			return (ft_putstr("(null)"));
	}
	else
	{
		if (flag.width > 0 && flag.dot == 1)
			return (ft_putstr_prewidth(str, flag));
		else if (flag.width > 0)
			return (ft_putstr_width(str, flag));
		else if (flag.dot == 1)
			return (ft_putstr_pre(str, flag.precision));
		else
			return (ft_putstr(str));
	}
}

int		put_hex(unsigned int num, t_flag flag, char b)
{
	int i;
	int bigs;

	i = 0;
	bigs = (b == 'X') ? 1 : 0;
	if (flag.dot == 1 && flag.precision == 0 && num == 0)
	{
		while (i++ < flag.width)
			write(1, " ", 1);
		return (flag.width);
	}
	else if (flag.width > 0 && flag.dot == 1)
		return (ft_puthex_prewidth(num, flag, bigs));
	else if (flag.width > 0 && flag.zero == 0)
		return (ft_puthex_width(num, flag, bigs));
	else if (flag.width > 0 && flag.zero == 1 && flag.neg == 1)
		return (ft_puthex_width(num, flag, bigs));
	else if (flag.dot == 1 || (flag.width > 0 && flag.zero == 1))
		return (ft_puthex_pre(num, flag, bigs));
	else
		return (ft_puthex(num, bigs));
}

int		put_mem(unsigned long n, t_flag flag)
{
	int i;

	i = 0;
	if (flag.dot == 1 && flag.precision == 0 && n == 0)
	{
		while (flag.neg == 0 && i++ < flag.width - 2)
			write(1, " ", 1);
		write(1, "0x", 2);
		while (flag.neg == 1 && i++ < flag.width - 2)
			write(1, " ", 1);
		return (i + 1);
	}
	if (flag.width > 0 && flag.dot == 1)
		return (ft_putmem_prewidth(n, flag));
	if (flag.width > 0 && flag.zero == 0)
		return (ft_putmem_width(n, flag));
	else if (flag.dot == 1 || (flag.width > 0 && flag.zero == 1))
		return (ft_putmem_pre(n, flag));
	else
		return (ft_putmem(n, 1));
}
