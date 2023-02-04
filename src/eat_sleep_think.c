/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:17:12 by yshimoda          #+#    #+#             */
/*   Updated: 2023/02/04 03:34 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	time_wait(t_philo *philo, time_t target_time, time_t time_to_wait)
{
	usleep(time_to_wait * 800);
	while (calc_elapsed_time(&philo->time_start) < target_time)
		usleep(100);
}

static bool	pick_up_fork(t_philo *philo, t_arg *arg)
{
	pthread_mutex_lock(philo->fork_right_mtx);
	if (!print_action(arg, calc_elapsed_time(&arg->time_start),
			&philo->id, TYPE_TAKE_FORK) || arg->num_of_philo == 1)
	{
		pthread_mutex_unlock(philo->fork_right_mtx);
		if (arg->num_of_philo == 1)
			usleep(arg->time_to_die * 1000 + 100);
		return (false);
	}
	pthread_mutex_lock(philo->fork_left_mtx);
	philo->time_end_take_fork = calc_elapsed_time(&philo->time_start);
	if (!print_action(arg, calc_elapsed_time(&arg->time_start), &philo->id,
			TYPE_TAKE_FORK) != 0)
	{
		pthread_mutex_unlock(philo->fork_right_mtx);
		pthread_mutex_unlock(philo->fork_left_mtx);
		return (false);
	}
	return (true);
}

bool	eat_philo(t_philo *philo, t_arg *arg)
{
	if (!pick_up_fork(philo, arg))
		return (false);
	if (!print_action(arg, calc_elapsed_time(&arg->time_start),
			&philo->id, TYPE_EAT))
	{
		pthread_mutex_unlock(philo->fork_right_mtx);
		pthread_mutex_unlock(philo->fork_left_mtx);
		return (false);
	}
	pthread_mutex_lock(&arg->philo_mtx[philo->id - 1]);
	philo->time_last_eat = get_time();
	pthread_mutex_unlock(&arg->philo_mtx[philo->id - 1]);
	time_wait(philo, philo->time_end_take_fork + arg->time_to_eat,
		arg->time_to_eat);
	pthread_mutex_unlock(philo->fork_right_mtx);
	pthread_mutex_unlock(philo->fork_left_mtx);
	pthread_mutex_lock(&arg->philo_mtx[philo->id - 1]);
	philo->num_of_eaten++;
	pthread_mutex_unlock(&arg->philo_mtx[philo->id - 1]);
	return (true);
}

bool	sleep_philo(t_philo *philo, t_arg *arg)
{
	time_t	time_start_sleep;

	time_start_sleep = calc_elapsed_time(&philo->time_start);
	if (!print_action(arg, calc_elapsed_time(&arg->time_start),
			&philo->id, TYPE_SLEEP))
		return (false);
	time_wait(philo, time_start_sleep + arg->time_to_sleep, arg->time_to_sleep);
	return (true);
}

bool	think_philo(t_philo *philo, t_arg *arg)
{
	if (!print_action(arg, calc_elapsed_time(&arg->time_start),
			&philo->id, TYPE_THINK))
		return (false);
	return (true);
}
