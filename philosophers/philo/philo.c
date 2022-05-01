/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 21:29:07 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/06/23 14:14:22 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philohead.h"

void	philo_delay(long long delay, t_philocore *philocore)
{
	long long i;

	i = get_timestamp();
	while (philocore->b_death != TRUE)
	{
		if (get_timestamp() - i >= delay)
			break ;
		usleep(50);
	}
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->philocore->mutex_fork_arr[philo->left_fork]);
	status_output(philo->philocore, philo->index, "has taken a fork");
	pthread_mutex_lock(&philo->philocore->mutex_fork_arr[philo->right_fork]);
	status_output(philo->philocore, philo->index, "has taken a fork");
	pthread_mutex_lock(&philo->philocore->mutex_status);
	status_output(philo->philocore, philo->index, "is eating");
	philo->eat_timer = get_timestamp();
	pthread_mutex_unlock(&philo->philocore->mutex_status);
	philo_delay(philo->workset->time_to_eat, philo->philocore);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->philocore->mutex_fork_arr[philo->left_fork]);
	pthread_mutex_unlock(&philo->philocore->mutex_fork_arr[philo->right_fork]);
}

void	*philo(void *void_philo)
{
	int		i;
	t_philo	*philo;

	philo = (t_philo*)void_philo;
	if (philo->index % 2)
		usleep(15000);
	i = 0;
	while (philo->philocore->b_death != TRUE)
	{
		philo_eat(philo);
		if (philo->philocore->b_eat == TRUE ||
		(philo->eat_count >= philo->workset->num_of_eat &&
		philo->workset->num_of_eat != -1))
			break ;
		status_output(philo->philocore, philo->index, "is sleeping");
		philo_delay(philo->workset->time_to_sleep, philo->philocore);
		status_output(philo->philocore, philo->index, "is thinking");
		i++;
	}
	return (NULL);
}
