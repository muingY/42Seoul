/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 11:55:21 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/03/31 11:58:55 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_avg_limit(t_stack *a, int limit)
{
	int		i;
	float	total;

	if (a->top == -1)
		return (0);
	i = 0;
	total = 0;
	while (a->stack[a->top - i] <= limit && a->stack[a->top - i] != 1)
	{
		total += a->stack[a->top - i];
		i++;
	}
	return ((int)(total / i + 0.5));
}

void	smart_rotate(t_stack *a, t_stack *b)
{
	int i;

	i = -1;
	while (++i < a->top + 1)
		if (a->stack[i] == get_max(a))
			break ;
	if (i <= (a->top + 1) / 2)
		stack_rrotate(b, "rrb\n");
	else
		stack_rotate(b, "rb\n");
}

void	split_2a(t_stack *a, t_stack *b, int avg, int size)
{
	while (size-- > 0)
	{
		if (b->top + 1 < 13)
			get_max_to_a(a, b);
		else
		{
			if (avg <= b->stack[b->top])
				stack_b2a(a, b, "pa\n");
			else
			{
				if (b->stack[b->top] == a->stack[0] + 1 ||
					b->stack[b->top] == 1)
				{
					stack_b2a(a, b, "pa\n");
					stack_rotate(a, "ra\n");
				}
				else
					stack_rotate(b, "rb\n");
			}
		}
	}
}

void	split_2b(t_stack *a, t_stack *b, int avg, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (avg > a->stack[a->top])
			stack_b2a(b, a, "pb\n");
		else
			stack_rotate(a, "ra\n");
		i++;
	}
}
