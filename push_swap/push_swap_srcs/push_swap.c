/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:34:33 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/03/31 11:59:49 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	issort(t_stack *a)
{
	int comp;
	int i;

	comp = a->stack[a->top];
	i = a->top - 1;
	while (i >= 0)
	{
		if (comp > a->stack[i])
			return (FALSE);
		else
			comp = a->stack[i];
		i--;
	}
	return (TRUE);
}

int		fill_stack(t_stack *a, char *argv[])
{
	int i;

	i = a->len;
	while (i > 0)
	{
		if (ft_isnbr(argv[i]) == 1)
		{
			if (chk_error(a, argv[i]) == 0)
				return (0);
			stack_push(a, ft_atoi(argv[i]));
		}
		else
			return (0);
		i--;
	}
	return (1);
}

int		main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		error("Error", -1);
	a = stack_new(argc - 1);
	b = stack_new(argc - 1);
	if (fill_stack(a, argv) != 1)
		error("Error", -1);
	if (issort(a) == TRUE)
		error("", 0);
	preprocess_stack(a);
	sort(a, b);
	stack_delete(a);
	stack_delete(b);
	return (0);
}
