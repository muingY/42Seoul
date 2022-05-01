/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 10:14:41 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/03/30 18:16:27 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_swap(t_stack *a, char *cmd)
{
	int		pop_data;
	int		tmp;
	t_stack *b;

	b = stack_new(a->len);
	if (a->top >= 1)
	{
		stack_pop(a, &pop_data);
		stack_push(b, pop_data);
		stack_pop(a, &pop_data);
		stack_pop(b, &tmp);
		stack_push(a, tmp);
		stack_push(a, pop_data);
	}
	stack_delete(b);
	write(1, cmd, ft_strlen(cmd));
}

void	stack_b2a(t_stack *a, t_stack *b, char *cmd)
{
	int		pop_data;

	if (b->top != -1)
	{
		stack_pop(b, &pop_data);
		stack_push(a, pop_data);
	}
	write(1, cmd, ft_strlen(cmd));
}

void	stack_rotate(t_stack *a, char *cmd)
{
	int		pop_data;
	int		top_data;
	t_stack	*b;

	b = stack_new(a->len);
	if (a->top >= 1)
	{
		stack_pop(a, &top_data);
		while (a->top != -1)
		{
			stack_pop(a, &pop_data);
			stack_push(b, pop_data);
		}
		stack_push(a, top_data);
		while (b->top != -1)
		{
			stack_pop(b, &pop_data);
			stack_push(a, pop_data);
		}
	}
	stack_delete(b);
	write(1, cmd, ft_strlen(cmd));
}

void	stack_rrotate(t_stack *a, char *cmd)
{
	int		pop_data;
	int		bottom_data;
	t_stack	*b;

	b = stack_new(a->len);
	if (a->top >= 1)
	{
		while (a->top != 0)
		{
			stack_pop(a, &pop_data);
			stack_push(b, pop_data);
		}
		stack_pop(a, &bottom_data);
		while (b->top != -1)
		{
			stack_pop(b, &pop_data);
			stack_push(a, pop_data);
		}
		stack_push(a, bottom_data);
	}
	stack_delete(b);
	write(1, cmd, ft_strlen(cmd));
}
