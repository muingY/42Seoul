/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 00:39:15 by seongcho          #+#    #+#             */
/*   Updated: 2021/05/09 14:45:22 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	history_init(t_hist *hist)
{
	hist->i = -1;
	hist->top = -1;
	hist->stack = NULL;
}

void	history_destory(t_hist *hist)
{
	int		i;

	if (hist->stack == NULL)
		return ;
	i = 0;
	while (i <= hist->top)
	{
		free(hist->stack[i]);
		i++;
	}
	free(hist->stack);
	history_init(hist);
}

int		history_add(t_hist *hist, char *input)
{
	char	**new_stack;
	int		i;

	if (hist->stack == NULL)
	{
		hist->stack = (char**)malloc(sizeof(char*));
		hist->stack[0] = ft_strdup(input);
		hist->top += 1;
		hist->i = hist->top;
		return (1);
	}
	new_stack = (char**)malloc(sizeof(char*) * (hist->top + 2));
	i = 0;
	while (i <= hist->top)
	{
		new_stack[i] = hist->stack[i];
		i++;
	}
	hist->top += 1;
	new_stack[hist->top] = ft_strdup(input);
	free(hist->stack);
	hist->stack = new_stack;
	hist->i = hist->top;
	return (1);
}

int		history_up(t_hist *hist)
{
	if (hist->i - 1 == -2)
		return (0);
	hist->i -= 1;
	return (1);
}

int		history_down(t_hist *hist)
{
	if (hist->i + 1 >= hist->top)
		return (0);
	hist->i += 1;
	return (1);
}
