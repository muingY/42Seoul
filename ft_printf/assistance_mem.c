/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assistance_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 20:57:45 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/01/21 11:57:04 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_memlen(unsigned long n)
{
	int len;

	len = 0;
	if (n / 16 > 0)
		len += ft_memlen(n / 16);
	len++;
	return (len);
}

int		ft_putmem(unsigned long n, int start)
{
	char	*set;
	int		i;
	int		len;

	len = 0;
	if (start)
	{
		write(1, "0x", 2);
		len += 2;
	}
	set = "0123456789abcdef";
	if (n / 16 > 0)
		len += ft_putmem(n / 16, 0);
	i = n % 16;
	write(1, &set[i], 1);
	len++;
	return (len);
}

int		ft_putmem_prewidth(unsigned long n, t_flag flag)
{
	int len;
	int padding;
	int count;

	count = flag.precision - ft_memlen(n);
	count = (count > 0) ? count : 0;
	padding = flag.width - count - ft_memlen(n) - 2;
	padding = (padding > 0) ? padding : 0;
	len = 2 + padding + count;
	while (flag.neg == 0 && padding-- > 0)
		write(1, " ", 1);
	write(1, "0x", 2);
	while (count-- > 0)
		write(1, "0", 1);
	len += ft_putmem(n, 0);
	while (flag.neg == 1 && padding-- > 0)
		write(1, " ", 1);
	return (len);
}

int		ft_putmem_width(unsigned long n, t_flag flag)
{
	int len;
	int padding;

	len = 0;
	padding = (flag.dot == 1) ? flag.precision : flag.width - 2;
	padding -= ft_memlen(n);
	while (flag.neg == 0 && padding-- > 0)
	{
		write(1, " ", 1);
		len++;
	}
	len += ft_putmem(n, 1);
	while (flag.neg == 1 && padding-- > 0)
	{
		write(1, " ", 1);
		len++;
	}
	return (len);
}

int		ft_putmem_pre(unsigned long n, t_flag flag)
{
	char	*set;
	int		i;
	int		len;
	int		count;

	write(1, "0x", 2);
	len = 2;
	count = (flag.dot == 1) ? flag.precision : flag.width - 2;
	count -= ft_memlen(n);
	while (count-- > 0)
	{
		write(1, "0", 1);
		len++;
	}
	set = "0123456789abcdef";
	if (n / 16 > 0)
		len += ft_putmem(n / 16, 0);
	i = n % 16;
	write(1, &set[i], 1);
	len++;
	return (len);
}
