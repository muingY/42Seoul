/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 12:53:06 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/03/13 20:40:56 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ssrrrrr(t_stack *a, t_stack *b, char operation)
{
	if (operation == '2')
	{
		stack_swap(a);
		stack_swap(b);
	}
	else if (operation == '7')
	{
		stack_rotate(a);
		stack_rotate(b);
	}
	else if (operation == '-')
	{
		stack_rrotate(a);
		stack_rrotate(b);
	}
}

void	execute_sub(t_stack *a, t_stack *b, char operation)
{
	if (operation == '0')
		stack_swap(a);
	else if (operation == '1')
		stack_swap(b);
	else if (operation == '2')
		ssrrrrr(a, b, operation);
	else if (operation == '3')
		stack_b2a(a, b);
	else if (operation == '4')
		stack_b2a(b, a);
	else if (operation == '5')
		stack_rotate(a);
	else if (operation == '6')
		stack_rotate(b);
	else if (operation == '7')
		ssrrrrr(a, b, operation);
	else if (operation == '8')
		stack_rrotate(a);
	else if (operation == '9')
		stack_rrotate(b);
	else if (operation == '-')
		ssrrrrr(a, b, operation);
}

void	execute(t_stack *a, t_stack *b, char *operation_list)
{
	while (*operation_list)
	{
		execute_sub(a, b, *operation_list);
		operation_list++;
	}
}
