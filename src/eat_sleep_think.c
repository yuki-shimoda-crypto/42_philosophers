/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:17:12 by yshimoda          #+#    #+#             */
/*   Updated: 2023/02/02 06:03:20 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	time_wait(long last_time, long wait_time)
{
	while (1)
	{
		if (get_time() - last_time >= wait_time)
			break ;
		usleep(100);
	}
}

bool	pick_up_fork(t_philo *philo, t_arg *arg)
{
	pthread_mutex_lock(philo->fork_right_mtx);
	if (!print_action(arg, calc_elapsed_time(philo->time_start), philo->id, TYPE_TAKE_FORK) || arg->num_of_philo == 1)
	{
		pthread_mutex_unlock(philo->fork_right_mtx);
		if (arg->num_of_philo == 1)
			usleep(arg->time_to_die * 1000 + 5000);
			// usleep(arg->time_to_die * 1000 + 100);
		return (false);
	}
	pthread_mutex_lock(philo->fork_left_mtx);
	philo->time_end_take_fork = calc_elapsed_time(philo->time_start);
	if (!print_action(arg, philo->time_end_take_fork, philo->id, TYPE_TAKE_FORK) != 0)
	{
		pthread_mutex_unlock(philo->fork_right_mtx);
		pthread_mutex_unlock(philo->fork_left_mtx);
		return (false);
	}
	return (true);
}

// bool	put_down_fork(t_philo *philo, t_arg *arg)
// {
// 	if (pthread_mutex_unlock(philo->fork_right_mtx) != 0)
// 		error_func(ERROR_MUTEX_UNLOCK, "pick_up_fork_mutex_unlock", __LINE__);
// 	if (pthread_mutex_unlock(philo->fork_left_mtx) != 0)
// 		error_func(ERROR_MUTEX_UNLOCK, "pick_up_fork_mutex_unlock", __LINE__);
// 	display_message(TYPE_SLEEP, get_time() - arg->start_time, philo->id, arg);
// 	usleep(philo->arg->time_to_sleep * 800);
// 	while (1)
// 	{
// 		if (get_time() - philo->last_eat_time >= arg->time_to_sleep)
// 			break ;
// 		usleep(100);
// 	}
// }

bool	eat(t_philo *philo, t_arg *arg)
{
	if (!print_action(arg, philo->time_end_take_fork, philo->id, TYPE_EAT))
	{
		pthread_mutex_unlock(philo->fork_right_mtx);
		pthread_mutex_unlock(philo->fork_left_mtx);
		return (false);
	}
	pthread_mutex_lock(&arg->philo_mtx[philo->id - 1]);
	philo->time_last_eat = get_time();
	pthread_mutex_unlock(&arg->philo_mtx[philo->id - 1]);
	// usleep(arg->time_to_eat * 800);
	time_wait(philo->time_last_eat, arg->time_to_eat);
	pthread_mutex_unlock(philo->fork_right_mtx);
	pthread_mutex_unlock(philo->fork_left_mtx);
	pthread_mutex_lock(&arg->philo_mtx[philo->id - 1]);
	philo->num_of_eaten++;
	pthread_mutex_unlock(&arg->philo_mtx[philo->id - 1]);
	return (true);
}

bool	philo_sleep(t_philo *philo, t_arg *arg)
{
	long	time_start_sleep;

	time_start_sleep = calc_elapsed_time(philo->time_start);
	if (!print_action(arg, time_start_sleep, philo->id, TYPE_SLEEP))
		return (false);
	time_wait(time_start_sleep, arg->time_to_sleep);
	return (true);
}

bool	think(t_philo *philo, t_arg *arg)
{
	if (!print_action(arg, calc_elapsed_time(philo->time_start), philo->id, TYPE_THINK))
		return (false);
	return (true);
}
