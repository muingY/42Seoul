/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assistance_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:28:15 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/01/21 14:36:00 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putchar_minwidth(char c, int width)
{
	int count;

	count = 0;
	write(1, &c, 1);
	while (count++ < width - 1)
		write(1, " ", 1);
	return (width);
}

int		ft_putchar_zerowidth(char c, int width)
{
	int count;

	count = 0;
	while (count++ < width - 1)
		write(1, "0", 1);
	write(1, &c, 1);
	return (width);
}

int		ft_putchar_width(char c, int width)
{
	int count;

	count = 0;
	while (count++ < width - 1)
		write(1, " ", 1);
	write(1, &c, 1);
	return (width);
}
