/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:09:02 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/03/31 10:32:43 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rank(t_stack *a, t_stack *da)
{
	int i;
	int j;

	i = a->top;
	while (i >= 0)
	{
		j = 0;
		while (j < da->top)
		{
			if (a->stack[i] == da->stack[da->top - j] &&
					da->stack[da->top - j] != 999999)
			{
				da->stack[da->top - j] = 999999;
				break ;
			}
			j++;
		}
		a->stack[i] = j + 1;
		i--;
	}
	da->top = -1;
}

int		partition_array(t_stack *a, int left, int right, int pivot)
{
	int tmp;

	while (left <= right)
	{
		while (a->stack[left] > pivot)
			left++;
		while (a->stack[right] < pivot)
			right--;
		if (left <= right)
		{
			tmp = a->stack[right];
			a->stack[right] = a->stack[left];
			a->stack[left] = tmp;
			left++;
			right--;
		}
	}
	return (left);
}

void	sort_complex(t_stack *b, int left, int right)
{
	int pivot;
	int index;

	if (left >= right)
		return ;
	pivot = b->stack[(right + left) / 2];
	index = partition_array(b, left, right, pivot);
	sort_complex(b, left, index - 1);
	sort_complex(b, index, right);
}
