/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_func2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 17:54:27 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/01/21 13:51:18 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_none(char c, t_flag flag)
{
	int padding;

	padding = flag.width - 1;
	if (c == '\0')
		return (0);
	while (flag.neg == 0 && flag.zero == 0 && padding-- > 0)
		write(1, " ", 1);
	while (flag.neg == 0 && flag.zero == 1 && padding-- > 0)
		write(1, "0", 1);
	write(1, &c, 1);
	while (flag.neg == 1 && padding-- > 0)
		write(1, " ", 1);
	if (flag.width > 0)
		return (flag.width);
	else
		return (1);
}
