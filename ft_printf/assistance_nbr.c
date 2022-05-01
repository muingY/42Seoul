/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assistance_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 17:24:53 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/01/21 14:32:16 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nbrlen(long n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int		ft_putnbr(long n)
{
	char	c;
	int		len;

	len = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		len++;
		n = -n;
	}
	if (n / 10 > 0)
		len += ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
	len++;
	return (len);
}

int		ft_putnbr_prewidth(long n, t_flag flag)
{
	int len;
	int count;
	int padding;

	len = 0;
	count = flag.precision - ft_nbrlen(n);
	count += (n < 0) ? 1 : 0;
	count = (count > 0) ? count : 0;
	padding = flag.width - ft_nbrlen(n) - count;
	padding = (padding > 0) ? padding : 0;
	len += padding + count + ft_nbrlen(n);
	while (flag.neg == 0 && padding-- > 0)
		write(1, " ", 1);
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	while (count-- > 0)
		write(1, "0", 1);
	ft_putnbr(n);
	while (flag.neg == 1 && padding-- > 0)
		write(1, " ", 1);
	return (len);
}

int		ft_putnbr_pre(long n, t_flag flag)
{
	int len;
	int count;

	len = 0;
	count = (flag.dot == 1) ? flag.precision : flag.width;
	count -= (n < 0 && flag.dot == 1) ? ft_nbrlen(n) - 1 : ft_nbrlen(n);
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		len++;
	}
	while (count-- > 0)
	{
		write(1, "0", 1);
		len++;
	}
	len += ft_putnbr(n);
	return (len);
}

int		ft_putnbr_width(long n, t_flag flag)
{
	int len;
	int padding;

	len = 0;
	padding = flag.width - ft_nbrlen(n);
	while (flag.neg == 0 && padding-- > 0)
	{
		write(1, " ", 1);
		len++;
	}
	len += ft_putnbr(n);
	while (flag.neg == 1 && padding-- > 0)
	{
		write(1, " ", 1);
		len++;
	}
	return (len);
}
