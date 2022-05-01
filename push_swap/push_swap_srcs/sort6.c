/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 11:58:12 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/03/31 11:58:53 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	backtrack(t_stack *a, t_stack *b, int limit)
{
	while (a->stack[a->top] <= limit && a->stack[a->top] != 1)
	{
		if (a->stack[a->top] == a->stack[0] + 1)
			stack_rotate(a, "ra\n");
		else
			stack_b2a(b, a, "pb\n");
	}
	if (get_min(b) == a->stack[0] + 1)
		push_swap(a, b);
}

void	backtrack_split(t_stack *a, t_stack *b, int limit)
{
	int c;
	int i;
	int avg;

	c = 0;
	avg = get_avg_limit(a, limit);
	while (a->stack[a->top] <= limit && a->stack[a->top] != 1)
	{
		if (a->stack[a->top] >= avg)
		{
			stack_rotate(a, "ra\n");
			c++;
		}
		else
			stack_b2a(b, a, "pb\n");
	}
	i = -1;
	while (++i < c)
		if (b->stack[b->top] != get_max(b))
			do_rrr(a, b);
		else
			stack_rrotate(a, "rra\n");
	if (get_min(b) == a->stack[0] + 1 && c > 0)
		push_swap(a, b);
}

void	push_swap(t_stack *a, t_stack *b)
{
	int max;

	if (b->top == -1)
		return ;
	max = get_max(b);
	split_2a(a, b, get_avg(b), b->top + 1);
	while ((a->stack[a->top] == a->stack[0] + 1 ||
		a->stack[a->top] == 1) && issort(a) == FALSE)
		stack_rotate(a, "ra\n");
	push_swap(a, b);
	if (get_size(a, max) >= 20)
		backtrack_split(a, b, max);
	backtrack(a, b, max);
}

void	backtrack_push_swap(t_stack *a, t_stack *b)
{
	if (issort(a) == TRUE)
		return ;
	split_2b(a, b, get_avg(a), a->top + 1);
	push_swap(a, b);
	if (get_size(a, get_max(a)) >= 20)
	{
		backtrack_split(a, b, get_max(a));
		backtrack_split(a, b, get_max(a));
	}
	backtrack(a, b, get_max(a));
}
