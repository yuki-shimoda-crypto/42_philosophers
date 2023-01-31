/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:17:12 by yshimoda          #+#    #+#             */
/*   Updated: 2023/01/31 18:30:22 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	pick_up_fork(t_philo *philo, t_arg *arg)
{
	if (!print_action(arg, calc_elapsed_time(philo->time_start), philo->id, TYPE_PUT_FORK) != 0)
		return (false);
		
	if (pthread_mutex_lock(philo->fork_right_m) != 0)
		error_func(ERROR_MUTEX_LOCK, "pick_up_fork_mutex_lock", __LINE__);
	display_message(TYPE_PUT_FORK, calc_time(get_time(), arg->start_time), philo->id, arg);
	if (pthread_mutex_lock(philo->fork_left_m) != 0)
		error_func(ERROR_MUTEX_LOCK, "pick_up_fork_mutex_lock", __LINE__);
	display_message(TYPE_PUT_FORK, calc_time(get_time(), arg->start_time), philo->id, arg);
	return (true);
}

void	put_down_fork(t_philo *philo, t_arg *arg)
{
	if (pthread_mutex_unlock(philo->fork_right_m) != 0)
		error_func(ERROR_MUTEX_UNLOCK, "pick_up_fork_mutex_unlock", __LINE__);
	if (pthread_mutex_unlock(philo->fork_left_m) != 0)
		error_func(ERROR_MUTEX_UNLOCK, "pick_up_fork_mutex_unlock", __LINE__);
	display_message(TYPE_SLEEP, get_time() - arg->start_time, philo->id, arg);
	usleep(philo->arg->time_to_sleep * 800);
	while (1)
	{
		if (get_time() - philo->last_eat_time >= arg->time_to_sleep)
			break ;
		usleep(100);
	}
}

void	eat(t_philo *philo, t_arg *arg)
{
	// last eat time
	if (pthread_mutex_lock(&philo->last_eat_time_m) != 0)
		error_func(ERROR_MUTEX_LOCK, "eat-mutex_lock", __LINE__);
	philo->last_eat_time = get_time();
	if (pthread_mutex_unlock(&philo->last_eat_time_m) != 0)
		error_func(ERROR_MUTEX_UNLOCK, "eat-mutex_unlock", __LINE__);
	// num of eaten
	if (pthread_mutex_lock(&philo->num_of_eaten_m) != 0)
		error_func(ERROR_MUTEX_LOCK, "eat-mutex_lock", __LINE__);
	philo->num_of_eaten++;
	if (pthread_mutex_unlock(&philo->num_of_eaten_m) != 0)
		error_func(ERROR_MUTEX_UNLOCK, "eat-mutex_unlock", __LINE__);
	display_message(TYPE_EAT, calc_time(philo->last_eat_time, arg->start_time), philo->id, arg);
	// usleep(philo->arg->time_to_eat * 1000);
	usleep(philo->arg->time_to_eat * 800);
	while (1)
	{
		if (get_time() - philo->last_eat_time >= arg->time_to_eat)
			break ;
		usleep(100);
	}
}

bool	think(t_philo *philo, t_arg *arg)
{
	if (!print_action(arg, calc_time(get_time(), philo->time_start), philo->id, TYPE_THINK))
		return (false);
	usleep(100);
	return (true);
}

static void	sleep_time_pass(t_philo *philo, long target_time)
{
	while (calc_elapsed_time(philo->time_start) < target_time)
		usleep(100);
}

bool	philo_sleep(t_philo *philo, t_arg *arg)
{
	long	time_start_sleep;

	time_start_sleep = calc_elapsed_time(philo->time_last_eat);
	if (!print_action(arg, time_start_sleep, philo->id, TYPE_SLEEP))
		return (false);
	sleep_time_pass(philo, time_start_sleep + arg->time_to_sleep);
	return (true);
}
