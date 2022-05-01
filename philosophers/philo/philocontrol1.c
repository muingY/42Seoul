/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philocontrol1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 21:05:52 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/06/23 14:09:29 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philohead.h"

t_bool	philocontrol_init_mutex(t_philocore *philocore)
{
	int i;

	philocore->mutex_fork_arr = (pthread_mutex_t*)
	malloc(sizeof(pthread_mutex_t) * philocore->workset.philo_num);
	if (philocore->mutex_fork_arr == NULL)
		return (FALSE);
	i = 0;
	while (i < philocore->workset.philo_num)
	{
		if (pthread_mutex_init(&philocore->mutex_fork_arr[i], NULL))
			return (FALSE);
		i++;
	}
	if (pthread_mutex_init(&philocore->mutex_output, NULL))
		return (FALSE);
	if (pthread_mutex_init(&philocore->mutex_status, NULL))
		return (FALSE);
	return (TRUE);
}

t_bool	philocontrol_init_philo(t_philocore *philocore)
{
	int i;

	philocore->philo_arr = (t_philo*)malloc(sizeof(t_philo) *
	philocore->workset.philo_num);
	if (philocore->philo_arr == NULL)
		return (FALSE);
	i = 0;
	while (i < philocore->workset.philo_num)
	{
		philocore->philo_arr[i].index = i;
		philocore->philo_arr[i].left_fork = i;
		philocore->philo_arr[i].right_fork =
		(i + 1) % philocore->workset.philo_num;
		philocore->philo_arr[i].workset = &philocore->workset;
		philocore->philo_arr[i].eat_timer = 0;
		philocore->philo_arr[i].eat_count = 0;
		philocore->philo_arr[i].philocore = philocore;
		i++;
	}
	return (TRUE);
}

t_bool	philocontrol_init(t_philocore *philocore, char **argv)
{
	philocore->workset.philo_num = ft_atoi(argv[1]);
	philocore->workset.time_to_die = ft_atoi(argv[2]);
	philocore->workset.time_to_eat = ft_atoi(argv[3]);
	philocore->workset.time_to_sleep = ft_atoi(argv[4]);
	philocore->b_death = FALSE;
	philocore->b_eat = FALSE;
	if (philocore->workset.philo_num < 1 ||
	philocore->workset.time_to_die < 0 ||
	philocore->workset.time_to_eat < 0 ||
	philocore->workset.time_to_sleep < 0)
		return (FALSE);
	if (philocore->workset.philo_num == 1)
		error_exit(0, "0ms 1 is died");
	philocore->workset.num_of_eat = -1;
	if (argv[5])
	{
		philocore->workset.num_of_eat = ft_atoi(argv[5]);
		if (philocore->workset.num_of_eat < 0)
			return (FALSE);
	}
	return (philocontrol_init_mutex(philocore) &&
	philocontrol_init_philo(philocore));
}
