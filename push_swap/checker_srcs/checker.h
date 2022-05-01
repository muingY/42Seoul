/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:08:35 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/03/25 21:07:36 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>

typedef char	t_bool;
# define TRUE 1
# define FALSE 0

typedef	struct	s_stack
{
	int			*stack;
	int			len;
	int			top;
}				t_stack;

/*
**Stack management
*/
t_stack			*stack_new(int len);
void			stack_delete(t_stack *stack);
t_bool			stack_pop(t_stack *stack, int *pop_data);
t_bool			stack_push(t_stack *stack, int push_data);
void			stack_swap(t_stack *a);
void			stack_b2a(t_stack *a, t_stack *b);
void			stack_rotate(t_stack *a);
void			stack_rrotate(t_stack *a);

/*
**Utils
*/
int				ft_strcmp(char *s1, char *s2);
int				ft_strlen(char *str);
char			*ft_strdup(char *str);
char			*ft_strjoin(char *s1, char *s2);
int				ft_atoi(const char *str);
int				ft_isnbr(const char *str);
int				get_next_line(char **line);
void			error(char *msg, int ret);
void			operation_switch_sub(char **list, char *str);
int				chk_error(t_stack *a, char *ns);

t_bool			issort(t_stack *stack);
void			execute(t_stack *a, t_stack *b, char *operation_list);

#endif
