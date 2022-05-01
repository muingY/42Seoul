/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 13:47:11 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/03/31 11:38:06 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_mini_3(t_stack *a)
{
	if (a->stack[0] > a->stack[2] && a->stack[0] > a->stack[1])
		stack_swap(a, "sa\n");
	else if (a->stack[1] < a->stack[2] && a->stack[0] < a->stack[1])
	{
		stack_swap(a, "sa\n");
		stack_rrotate(a, "rra\n");
	}
	else if (a->stack[1] < a->stack[2] && a->stack[0] > a->stack[1])
		stack_rotate(a, "ra\n");
	else if (a->stack[1] > a->stack[0] && a->stack[1] > a->stack[2]
	&& a->stack[2] < a->stack[0])
	{
		stack_swap(a, "sa\n");
		stack_rotate(a, "ra\n");
	}
	else if (a->stack[1] > a->stack[0] && a->stack[1] > a->stack[2]
	&& a->stack[2] > a->stack[0])
		stack_rrotate(a, "rra\n");
}

void	sort_mini_5(t_stack *a, t_stack *b)
{
	while (a->stack[a->top] != 0)
	{
		if (a->stack[0] == 0)
			stack_rrotate(a, "rra\n");
		else
			stack_rotate(a, "ra\n");
	}
	stack_b2a(b, a, "pb\n");
	while (a->stack[a->top] != 1 && a->len == 5)
	{
		if (a->stack[0] == 1)
			stack_rrotate(a, "rra\n");
		else
			stack_rotate(a, "ra\n");
	}
	if (a->len == 5)
		stack_b2a(b, a, "pb\n");
	if (issort(a) == FALSE)
		sort_mini_3(a);
	stack_b2a(a, b, "pa\n");
	if (a->len == 5)
		stack_b2a(a, b, "pa\n");
}

void	sort_mini(t_stack *a, t_stack *b)
{
	if (a->len == 2)
		stack_swap(a, "sa\n");
	else if (a->len == 3)
		sort_mini_3(a);
	else
		sort_mini_5(a, b);
}

void	sort(t_stack *a, t_stack *b)
{
	if (issort(a) == TRUE)
		return ;
	if (a->len <= 5)
		sort_mini(a, b);
	else
	{
		stack_copy(b, a);
		sort_complex(b, 0, b->top);
		rank(a, b);
		backtrack_push_swap(a, b);
	}
}
