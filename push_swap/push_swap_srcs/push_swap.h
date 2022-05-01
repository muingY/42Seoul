/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:08:35 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/03/31 11:56:20 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
t_bool			stack_copy(t_stack *destination, t_stack *p);
void			stack_swap(t_stack *a, char *cmd);
void			stack_b2a(t_stack *a, t_stack *b, char *cmd);
void			stack_rotate(t_stack *a, char *cmd);
void			stack_rrotate(t_stack *a, char *cmd);

/*
**Utils
*/
int				ft_strcmp(char *s1, char *s2);
int				ft_strlen(char *str);
char			*ft_strdup(char *str);
char			*ft_strjoin(char *s1, char *s2);
int				ft_atoi(const char *str);
int				ft_isnbr(const char *str);
void			error(char *msg, int ret);
int				ft_abs(int n);
int				chk_error(t_stack *a, char *ns);
void			do_rrr(t_stack *a, t_stack *b);

t_bool			issort(t_stack *stack);
void			preprocess_stack(t_stack *a);
void			rank(t_stack *a, t_stack *va);
int				get_avg(t_stack *a);
int				get_min(t_stack *a);
int				get_max(t_stack *b);
void			get_max_to_a(t_stack *a, t_stack *b);
int				get_size(t_stack *a, int limit);
int				get_avg_limit(t_stack *a, int limit);
void			smart_rotate(t_stack *a, t_stack *b);
void			split_2a(t_stack *a, t_stack *b, int avg, int size);
void			split_2b(t_stack *a, t_stack *b, int avg, int size);
void			backtrack_split(t_stack *a, t_stack *b, int limit);
void			backtrack(t_stack *a, t_stack *b, int limit);
void			push_swap(t_stack *a, t_stack *b);
void			sort_complex(t_stack *b, int left, int right);
void			backtrack_push_swap(t_stack *a, t_stack *b);
void			sort(t_stack *a, t_stack *b);

#endif
