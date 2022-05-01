/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:48:51 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/03/31 11:57:45 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_avg(t_stack *a)
{
	int		i;
	float	total;

	total = 0.0;
	if (a->top == -1)
		return (0);
	i = a->top;
	while (i >= 0)
	{
		total += a->stack[i];
		i--;
	}
	return ((int)(total / (int)a->top + 0.5));
}

int		get_min(t_stack *a)
{
	int i;
	int min;

	if (a->top == -1)
		return (0);
	i = 0;
	min = a->stack[i];
	while (i <= a->top)
	{
		if (min > a->stack[i])
			min = a->stack[i];
		i++;
	}
	return (min);
}

int		get_max(t_stack *b)
{
	int i;
	int max;

	if (b->top == -1)
		return (0);
	i = 0;
	max = 0;
	while (i <= b->top)
	{
		if (max < b->stack[i])
			max = b->stack[i];
		i++;
	}
	return (max);
}

void	get_max_to_a(t_stack *a, t_stack *b)
{
	if (get_max(b) == b->stack[b->top])
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
			smart_rotate(a, b);
	}
}

int		get_size(t_stack *a, int limit)
{
	int i;

	if (a->top == -1)
		return (0);
	i = 0;
	while (a->stack[a->top - i] <= limit && a->stack[a->top - i] != 1)
		i++;
	return (i);
}
