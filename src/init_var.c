/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:56:39 by yshimoda          #+#    #+#             */
/*   Updated: 2023/01/23 05:05:09by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	init_philo(t_philo *philo, t_arg *arg, int i)
{
	philo->last_eat_time = arg->start_time;
	philo->num_of_eaten = 0;
	pthread_mutex_init(&philo->m_last_eat_time, NULL);
	pthread_mutex_init(&philo->m_num_of_eaten, NULL);
	philo->right_fork = &arg->forks[i];
	if (i == MAX_PHILO)
		philo->left_fork = &arg->forks[0];
	else
		philo->left_fork = &arg->forks[i + 1];
	return ;
}

static void	init_arg_mutex(t_arg *arg)
{
	int		i;

	if (pthread_mutex_init(&(arg->dead_m), NULL) != 0)
		error_func(ERROR_MUTEX_INIT);
	if (pthread_mutex_init(&(arg->finish_m), NULL) != 0)
		error_func(ERROR_MUTEX_INIT);
	if (pthread_mutex_init(&(arg->write_mutex), NULL) != 0)
		error_func(ERROR_MUTEX_INIT);
	i = 0;
	while (i < MAX_PHILO)
	{
		if (pthread_mutex_init(&(arg->fork_m[i]), NULL) != 0)
			error_func(ERROR_MUTEX_INIT);
		i++;
	}
	return ;
}

void	init_arg(t_arg *arg)
{
	int		i;

	i = 0;
	arg->dead = false;
	arg->finish = false;
	init_arg_mutex(arg);
//	while (i < MAX_PHILO)
//	{
//		init_philo(&arg->philo[i], arg, i);
//		i++;
//	}
	gettimeofday(&arg->start_time, NULL);
	return ;
}
