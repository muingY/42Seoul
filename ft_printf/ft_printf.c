/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:00:40 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/01/21 14:08:26 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		format_switch(const char *str, int *i, va_list args_list)
{
	t_flag	flag;
	int		len;

	*i += 1;
	flag_init(str, i, &flag, args_list);
	if (str[*i] == 'd' || str[*i] == 'i')
		len = put_int(va_arg(args_list, int), flag);
	else if (str[*i] == 'u')
		len = put_int(va_arg(args_list, unsigned int), flag);
	else if (str[*i] == 'c')
		len = put_char(va_arg(args_list, int), flag);
	else if (str[*i] == 's')
		len = put_str(va_arg(args_list, char*), flag);
	else if (str[*i] == 'x' || str[*i] == 'X')
		len = put_hex(va_arg(args_list, unsigned int), flag, str[*i]);
	else if (str[*i] == 'p')
		len = put_mem(va_arg(args_list, unsigned long), flag);
	else
		len = put_none(str[*i], flag);
	if (str[*i] != '\0')
		*i += 1;
	return (len);
}

int		ft_printf(const char *str, ...)
{
	va_list	args_list;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args_list, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			len += format_switch(str, &i, args_list);
		else
		{
			write(1, &str[i++], 1);
			len++;
		}
	}
	va_end(args_list);
	return (len);
}
