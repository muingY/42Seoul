/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assistance_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 19:03:45 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/01/20 20:50:19 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_hexlen(unsigned int n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

int		ft_puthex(unsigned int n, int b)
{
	char	*set;
	int		len;
	int		i;

	if (b == 1)
		set = "0123456789ABCDEF";
	else
		set = "0123456789abcdef";
	len = 0;
	if (n / 16 > 0)
		len += ft_puthex(n / 16, b);
	i = n % 16;
	write(1, &set[i], 1);
	len++;
	return (len);
}

int		ft_puthex_prewidth(unsigned int n, t_flag flag, int b)
{
	int len;
	int count;
	int padding;

	len = 0;
	count = flag.precision - ft_hexlen(n);
	count = (count > 0) ? count : 0;
	padding = flag.width - ft_hexlen(n) - count;
	padding = (padding > 0) ? padding : 0;
	len += padding + count + ft_hexlen(n);
	while (flag.neg == 0 && padding-- > 0)
		write(1, " ", 1);
	while (count-- > 0)
		write(1, "0", 1);
	ft_puthex(n, b);
	while (flag.neg == 1 && padding-- > 0)
		write(1, " ", 1);
	return (len);
}

int		ft_puthex_pre(unsigned int n, t_flag flag, int b)
{
	int len;
	int count;

	len = 0;
	count = (flag.dot == 1) ? flag.precision : flag.width;
	count -= ft_hexlen(n);
	while (count-- > 0)
	{
		write(1, "0", 1);
		len++;
	}
	len += ft_puthex(n, b);
	return (len);
}

int		ft_puthex_width(unsigned int n, t_flag flag, int b)
{
	int len;
	int padding;

	len = 0;
	padding = flag.width - ft_hexlen(n);
	while (flag.neg == 0 && padding-- > 0)
	{
		write(1, " ", 1);
		len++;
	}
	len += ft_puthex(n, b);
	while (flag.neg == 1 && padding-- > 0)
	{
		write(1, " ", 1);
		len++;
	}
	return (len);
}
