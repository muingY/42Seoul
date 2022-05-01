/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philocontrol2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 22:53:26 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/06/23 14:07:17 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philohead.h"

void	status_output(t_philocore *philocore, int index, char *str)
{
	pthread_mutex_lock(&philocore->mutex_output);
	if (philocore->b_death != TRUE)
		printf("%llims %i %s\n", get_timestamp() - philocore->start_timestamp,
		index + 1, str);
	pthread_mutex_unlock(&philocore->mutex_output);
}

void	death_check_sub(t_philocore *philocore, int i)
{
	pthread_mutex_lock(&philocore->mutex_status);
	if (get_timestamp() - philocore->philo_arr[i].eat_timer >
	philocore->workset.time_to_die)
	{
		status_output(philocore, i, "died");
		philocore->b_death = TRUE;
	}
	pthread_mutex_unlock(&philocore->mutex_status);
	usleep(100);
}

void	death_check(t_philocore *philocore)
{
	int i;

	while (philocore->b_eat == FALSE)
	{
		i = 0;
		while (i < philocore->workset.philo_num && philocore->b_death != TRUE)
		{
			death_check_sub(philocore, i);
			i++;
		}
		if (philocore->b_death == TRUE)
			break ;
		i = 0;
		while (philocore->workset.num_of_eat != -1 &&
		i < philocore->workset.philo_num &&
		philocore->philo_arr[i].eat_count >= philocore->workset.num_of_eat)
			i++;
		if (i == philocore->workset.philo_num)
			philocore->b_eat = TRUE;
	}
}

t_bool	philocontrol_start(t_philocore *philocore)
{
	int		i;

	i = 0;
	philocore->start_timestamp = get_timestamp();
	while (i < philocore->workset.philo_num)
	{
		if (pthread_create(&philocore->philo_arr[i].thread, NULL, philo,
		(void*)(&philocore->philo_arr[i])))
			return (FALSE);
		philocore->philo_arr[i].eat_timer = get_timestamp();
		i++;
	}
	death_check(philocore);
	return (TRUE);
}

void	philocontrol_destroy(t_philocore *philocore)
{
	int i;

	i = 0;
	while (i < philocore->workset.philo_num)
	{
		pthread_join(philocore->philo_arr[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < philocore->workset.philo_num)
	{
		pthread_mutex_destroy(&philocore->mutex_fork_arr[i]);
		i++;
	}
	pthread_mutex_destroy(&philocore->mutex_output);
}
