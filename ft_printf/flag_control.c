/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:45:49 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/01/21 13:56:04 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	is_flag_format(const char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
	c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (TRUE);
	return (FALSE);
}

t_bool	is_flag_valid(const char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
	c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (TRUE);
	if (c == '-' || c == '.' || c == '*')
		return (TRUE);
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

int		ft_atoi_star(const char *str, int *i, va_list args_list)
{
	int num;

	num = 0;
	if (str[*i] == '.')
		*i += 1;
	if (str[*i] == '*')
	{
		num = va_arg(args_list, unsigned int);
		return (num);
	}
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		num = (str[*i] - 48) + num * 10;
		*i += 1;
	}
	*i -= 1;
	return (num);
}

void	neg_star(t_flag *flag)
{
	if (flag->precision < 0)
	{
		flag->dot = 0;
		flag->precision = 0;
	}
	else if (flag->width < 0)
	{
		flag->neg = 1;
		flag->width = -flag->width;
	}
}

void	flag_init(const char *str, int *i, t_flag *flag, va_list args_list)
{
	flag->neg = 0;
	flag->zero = 0;
	flag->dot = 0;
	flag->precision = 0;
	flag->width = 0;
	while (is_flag_format(str[*i]) == FALSE && is_flag_valid(str[*i]))
	{
		if (str[*i] == '-')
			flag->neg = 1;
		else if (str[*i] == '0')
			flag->zero = 1;
		else if (str[*i] == '.')
		{
			flag->dot = 1;
			flag->precision = ft_atoi_star(str, i, args_list);
		}
		else if (str[*i] == '*' || (str[*i] >= '1' && str[*i] <= '9'))
			flag->width = ft_atoi_star(str, i, args_list);
		if (flag->precision < 0 || flag->width < 0)
			neg_star(flag);
		*i += 1;
	}
}
