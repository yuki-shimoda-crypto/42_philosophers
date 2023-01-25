/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:17:12 by yshimoda          #+#    #+#             */
/*   Updated: 2023/01/25 17:40:27 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	pick_up_fork(t_philo *philo, t_arg *arg)
{
	if (pthread_mutex_lock(philo->fork_right_m) != 0)
	{
		printf("%s\t%d\n", "pick_up_fork_mutex_lock", __LINE__);
		error_func(ERROR_MUTEX_LOCK);
	}
	display_message(TYPE_PUT_FORK, calc_time(get_time(), arg->start_time), philo->id, arg);
	if (pthread_mutex_lock(philo->fork_left_m) != 0)
	{
		printf("%s\t%d\n", "pick_up_fork_mutex_lock", __LINE__);
		error_func(ERROR_MUTEX_LOCK);
	}
	display_message(TYPE_PUT_FORK, calc_time(get_time(), arg->start_time), philo->id, arg);
}

void	put_down_fork(t_philo *philo, t_arg *arg)
{
	if (pthread_mutex_unlock(philo->fork_right_m) != 0)
	{
		printf("%s\t%d\n", "put_down_fork-mutex_unlock", __LINE__);
		error_func(ERROR_MUTEX_UNLOCK);
	}
	if (pthread_mutex_unlock(philo->fork_left_m) != 0)
	{
		printf("%s\t%d\n", "put_down_fork-mutex_unlock", __LINE__);
		error_func(ERROR_MUTEX_UNLOCK);
	}

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
	{
		printf("%s\t%d\n", "eat-mutex_lock", __LINE__);
		error_func(ERROR_MUTEX_LOCK);
	}
	philo->last_eat_time = get_time();
	if (pthread_mutex_unlock(&philo->last_eat_time_m) != 0)
	{
		printf("%s\t%d\n", "eat-mutex_unlock", __LINE__);
		error_func(ERROR_MUTEX_UNLOCK);
	}

	// num of eaten
	if (pthread_mutex_lock(&philo->num_of_eaten_m) != 0)
	{
		printf("%s\t%d\n", "eat-mutex_lock", __LINE__);
		error_func(ERROR_MUTEX_LOCK);
	}
	philo->num_of_eaten++;
	if (pthread_mutex_unlock(&philo->num_of_eaten_m) != 0)
	{
		printf("%s\t%d\n", "eat-mutex_unlock", __LINE__);
		error_func(ERROR_MUTEX_LOCK);
	}

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

void	think(t_philo *philo, t_arg *arg)
{
	display_message(TYPE_THINK, get_time() - arg->start_time, philo->id, arg);
}

void	philo_sleep(t_philo *philo, t_arg *arg)
{
	display_message(TYPE_SLEEP, get_time() - arg->start_time, philo->id, arg);
}
