/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assistance_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:36:31 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/01/21 14:38:05 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int		ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
	return (i);
}

int		ft_putstr_prewidth(char *str, t_flag flag)
{
	int		size_s;
	int		size_padding;
	int		i;
	char	c;

	c = ' ';
	if (flag.zero == 1 && flag.neg == 0)
		c = '0';
	size_s =
	(ft_strlen(str) < flag.precision) ? ft_strlen(str) : flag.precision;
	size_padding = (flag.width > size_s) ? flag.width - size_s : 0;
	i = 0;
	while (flag.neg == 1 && i < flag.precision && str[i] != '\0')
		write(1, &str[i++], 1);
	i = 0;
	while (i++ < size_padding)
		write(1, &c, 1);
	i = 0;
	while (flag.neg == 0 && i < flag.precision && str[i] != '\0')
		write(1, &str[i++], 1);
	return (size_s > flag.width ? size_s : flag.width);
}

int		ft_putstr_width(char *str, t_flag flag)
{
	int		size_padding;
	int		i;
	char	c;

	c = ' ';
	if (flag.zero == 1 && flag.neg == 0)
		c = '0';
	size_padding =
	(flag.width > ft_strlen(str)) ? flag.width - ft_strlen(str) : 0;
	i = 0;
	while (flag.neg == 1 && str[i] != '\0')
		write(1, &str[i++], 1);
	i = 0;
	while (i++ < size_padding)
		write(1, &c, 1);
	i = 0;
	while (flag.neg == 0 && str[i] != '\0')
		write(1, &str[i++], 1);
	return (ft_strlen(str) > flag.width ? ft_strlen(str) : flag.width);
}

int		ft_putstr_pre(char *str, int precision)
{
	int size_s;
	int i;

	size_s = (ft_strlen(str) < precision) ? ft_strlen(str) : precision;
	i = 0;
	while (i < size_s && str[i] != '\0')
		write(1, &str[i++], 1);
	return (size_s);
}
