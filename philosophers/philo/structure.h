/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 09:23:43 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/06/23 14:03:24 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include <pthread.h>
# include <sys/time.h>

typedef char		t_bool;
# define TRUE 1
# define FALSE 0

typedef struct			s_workset
{
	int					philo_num;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_of_eat;
}						t_workset;

struct s_philocore;

typedef struct			s_philo
{
	int					index;
	int					left_fork;
	int					right_fork;
	t_workset			*workset;
	long long			eat_timer;
	int					eat_count;
	struct s_philocore	*philocore;
	pthread_t			thread;
}						t_philo;

typedef struct			s_philocore
{
	t_workset			workset;
	t_bool				b_death;
	t_bool				b_eat;
	long long			start_timestamp;
	pthread_mutex_t		mutex_status;
	pthread_mutex_t		*mutex_fork_arr;
	t_philo				*philo_arr;
	pthread_mutex_t		mutex_output;
}						t_philocore;

#endif
