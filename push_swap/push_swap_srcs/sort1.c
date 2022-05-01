/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:19:29 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/03/30 19:01:28 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		search_smallest(t_stack *a)
{
	int	ret;
	int	i;

	if (a->top == 0)
		return (-1);
	i = 1;
	ret = 0;
	while (i <= a->top)
	{
		if (a->stack[ret] > a->stack[i])
			ret = i;
		i++;
	}
	return (ret);
}

int		search_smallest_comp(t_stack *a, int comp)
{
	int	ret;
	int	i;

	if (a->top == 0)
		return (-1);
	i = 1;
	ret = 0;
	while (i <= a->top)
	{
		if (a->stack[ret] > a->stack[i] && a->stack[i] > comp)
			ret = i;
		else if (a->stack[ret] <= comp)
			ret++;
		i++;
	}
	return (ret);
}

void	preprocess_stack(t_stack *a)
{
	int	data;
	int	comp;
	int tmp;

	data = 0;
	comp = a->stack[search_smallest(a)];
	a->stack[search_smallest(a)] = data++;
	while (data <= a->top)
	{
		tmp = a->stack[search_smallest_comp(a, comp)];
		a->stack[search_smallest_comp(a, comp)] = data++;
		comp = tmp;
	}
}
