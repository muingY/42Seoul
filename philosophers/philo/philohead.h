/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philohead.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 09:20:13 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/06/22 18:23:13 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOHEAD_H
# define PHILOHEAD_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include "structure.h"

/*
**Utils
*/
int			ft_atoi(const char *nptr);
char		*ft_strdup(const char *s);
int			error(int ret, char *errmsg);
void		error_exit(int ret, char *errmsg);
long long	get_timestamp();

/*
**Philo
*/
void		*philo(void *arg);

/*
**PhiloControl
*/
t_bool		philocontrol_init(t_philocore *philocore, char **argv);
t_bool		philocontrol_start(t_philocore *philocore);
void		philocontrol_destroy(t_philocore *philocore);
void		status_output(t_philocore *philocore, int index, char *str);

#endif
