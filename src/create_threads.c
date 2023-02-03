/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:53:06 by yshimoda          #+#    #+#             */
/*   Updated: 2023/02/04 03:39:59 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static inline void	init_time(t_philo *philo, t_arg *arg)
{
	pthread_mutex_lock(&arg->philo_mtx[philo->id - 1]);
	philo->time_start = get_time();
	philo->time_last_eat = philo->time_start;
	pthread_mutex_unlock(&arg->philo_mtx[philo->id - 1]);
}

static void	*routine_philo(void *philo_void)
{
	t_philo	*philo;
	t_arg	*arg;

	philo = philo_void;
	arg = philo->arg;
	init_time(philo, arg);
	if (philo->id % 2 == 0
		|| (philo->id == arg->num_of_philo && arg->num_of_philo != 1))
	{
		think(philo, arg);
		usleep(100);
	}
	while (1)
	{
		if (!pick_up_fork(philo, arg))
			break ;
		if (!eat(philo, arg))
			break ;
		if (!philo_sleep(philo, arg))
			break ;
		if (!think(philo, arg))
			break ;
	}
	return (NULL);
}

void	create_threads(t_arg *arg)
{
	int		i;

	i = 0;
	arg->time_start = get_time();
	while (i < arg->num_of_philo)
	{
		pthread_create(&arg->philo[i].thread, NULL,
			routine_philo, &arg->philo[i]);
		i++;
	}
	pthread_create(&arg->thread_monitor, NULL, monitor, arg);
	return ;
}
