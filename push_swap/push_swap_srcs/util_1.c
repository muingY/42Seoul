/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 21:00:25 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/03/20 14:29:47 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	return (1);
}

int		ft_atoi(const char *str)
{
	int ret;
	int neg;

	neg = 1;
	if (*str == '-')
	{
		neg *= -1;
		str++;
	}
	ret = 0;
	while (*str)
	{
		ret *= 10;
		ret += (int)*str - '0';
		str++;
	}
	return (ret * neg);
}

int		ft_isnbr(const char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

void	error(char *msg, int ret)
{
	write(1, msg, ft_strlen(msg));
	write(1, "\n", 1);
	exit(ret);
}

void	operation_switch_sub(char **list, char *str)
{
	char *tmp;

	tmp = ft_strjoin(*list, str);
	free(*list);
	*list = tmp;
}
