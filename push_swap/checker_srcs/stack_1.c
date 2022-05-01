/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 09:57:54 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/03/13 20:40:08 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*stack_new(int len)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		error("stack_new malloc fail", -1);
	new->len = len;
	new->top = -1;
	new->stack = malloc(sizeof(int) * len);
	if (new->stack == NULL)
		error("stack_new stack malloc fail", -1);
	return (new);
}

void	stack_delete(t_stack *stack)
{
	if (stack->stack != NULL)
		free(stack->stack);
	if (stack != NULL)
		free(stack);
}

t_bool	stack_pop(t_stack *stack, int *pop_data)
{
	if (stack->top == -1 || stack->top > stack->len - 1)
		return (FALSE);
	*pop_data = stack->stack[stack->top];
	stack->stack[stack->top] = 0;
	stack->top--;
	return (TRUE);
}

t_bool	stack_push(t_stack *stack, int push_data)
{
	if (stack->top >= stack->len - 1)
		return (FALSE);
	stack->stack[stack->top + 1] = push_data;
	stack->top++;
	return (TRUE);
}
