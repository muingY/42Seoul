/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 21:07:08 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/03/27 15:28:19 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		chk_error(t_stack *a, char *ns)
{
	int			i;
	int			neg;
	long long	ln;

	i = 0;
	while (i <= a->top)
		if (a->stack[i++] == ft_atoi(ns))
			return (0);
	neg = 1;
	ln = 0;
	while (*ns)
	{
		if (*ns == '-')
		{
			neg = -1;
			ns++;
		}
		ln = ln * 10 + (*ns - '0');
		if (ln * (long long)neg < -2147483648
		|| ln * (long long)neg > 2147483647)
			return (0);
		ns++;
	}
	return (1);
}

void	do_rrr(t_stack *a, t_stack *b)
{
	stack_rrotate(a, "rrr\n");
	stack_rrotate(b, "");
}
