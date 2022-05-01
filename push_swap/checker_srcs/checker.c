/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:34:25 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/03/29 12:21:35 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_bool	issort(t_stack *stack)
{
	int		comp;
	int		pop_data;

	if (stack->top > 0)
	{
		stack_pop(stack, &comp);
		while (stack->top >= 0)
		{
			stack_pop(stack, &pop_data);
			if (pop_data < comp)
				return (FALSE);
			comp = pop_data;
		}
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

/*
**_"0" = sa
**_"1" = sb
**_"2" = ss
**_"3" = pa
**_"4" = pb
**_"5" = ra
**_"6" = rb
**_"7" = rr
**_"8" = rra
**_"9" = rrb
**_"-" = rrr
*/

int		operation_switch(char **list, char *line)
{
	if (ft_strcmp(line, "sa") == 1)
		operation_switch_sub(list, "0");
	else if (ft_strcmp(line, "sb") == 1)
		operation_switch_sub(list, "1");
	else if (ft_strcmp(line, "ss") == 1)
		operation_switch_sub(list, "2");
	else if (ft_strcmp(line, "pa") == 1)
		operation_switch_sub(list, "3");
	else if (ft_strcmp(line, "pb") == 1)
		operation_switch_sub(list, "4");
	else if (ft_strcmp(line, "ra") == 1)
		operation_switch_sub(list, "5");
	else if (ft_strcmp(line, "rb") == 1)
		operation_switch_sub(list, "6");
	else if (ft_strcmp(line, "rr") == 1)
		operation_switch_sub(list, "7");
	else if (ft_strcmp(line, "rra") == 1)
		operation_switch_sub(list, "8");
	else if (ft_strcmp(line, "rrb") == 1)
		operation_switch_sub(list, "9");
	else if (ft_strcmp(line, "rrr") == 1)
		operation_switch_sub(list, "-");
	else
		return (0);
	return (1);
}

int		operation_read(char **list)
{
	char	*line;

	while (get_next_line(&line) > 0)
	{
		if (operation_switch(list, line) != 1 && line[0] != '\0')
		{
			free(line);
			return (0);
		}
		free(line);
	}
	if (operation_switch(list, line) != 1 && line[0] != '\0')
	{
		free(line);
		return (0);
	}
	return (1);
}

int		main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack *b;
	char	*operation_list;

	if (argc == 1)
		error("", 0);
	a = stack_new(argc - 1);
	b = stack_new(argc - 1);
	if (fill_stack(a, argv) != 1)
		error("Error", -1);
	operation_list = ft_strdup("");
	if (operation_read(&operation_list) != 1)
		error("Error", -1);
	execute(a, b, operation_list);
	free(operation_list);
	if (issort(a) == TRUE)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	stack_delete(a);
	stack_delete(b);
	return (0);
}
