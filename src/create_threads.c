/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:53:06 by yshimoda          #+#    #+#             */
/*   Updated: 2023/01/25 11:31:17y yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	is_philo_starve(t_arg *arg)
{
	int	i;

	i = 0;
	while (i < arg->num_of_philo)
	{
		pthread_mutex_lock(&arg->philo_mtx[i]);
		if (arg->time_to_die < calc_elapsed_time(arg->philo[i].time_last_eat))
		{
			arg->dead_num = i;
			return (true);
		}
		pthread_mutex_unlock(&arg->philo_mtx[i]);
		i++;
	}
	return (false);
}


static bool	is_num_of_eat_reached(t_arg *arg)
{
	int	i;

	i = 0;
	while (i < arg->num_of_philo)
	{
		pthread_mutex_lock(&arg->philo_mtx[i]);
		if (arg->num_of_must_eat <= arg->philo[i].num_of_eaten)
		{
			pthread_mutex_unlock(&arg->philo_mtx[i]);
			return (true);
		}
		pthread_mutex_unlock(&arg->philo_mtx[i]);
		i++;
	}
	return (false);
}


static void	*monitor(void *arg_void)
{
	t_philo	*philo;
	t_arg	*arg;

	arg = arg_void;
	philo = arg->philo;
	usleep(arg->time_to_die / 2);
	while (1)
	{
		if (is_num_of_eat_reached(arg))
			break ;
		if (is_philo_starve(arg))
			break ;
		usleep(1000);
	}
	pthread_mutex_lock(&arg->write_exit_mtx);
	printf("%ld %d %s\n", calc_elapsed_time(arg->philo[arg->dead_num].time_start), arg->dead_num + 1, TYPE_DIE);
	arg->is_exit = true;
	pthread_mutex_unlock(&arg->write_exit_mtx);
	return (NULL);
}


bool	print_action(t_arg *arg, long timestamp, int id, const char *action)
{
	if (pthread_mutex_lock(&arg->write_exit_mtx) != 0)
		error_func(ERROR_MUTEX_LOCK, "print_action", __LINE__);
	if (arg->is_exit)
	{
		if (pthread_mutex_unlock(&arg->write_exit_mtx) != 0)
			error_func(ERROR_MUTEX_UNLOCK, "print_action", __LINE__);
		return (false);
	}
	printf("%ld %d %s\n", timestamp, id, action);
	pthread_mutex_unlock(&arg->write_exit_mtx);
	return (true);
}

static void	*routine_philo(void *philo_void)
{
	t_philo	*philo;
	t_arg	*arg;

	philo = philo_void;
	arg = philo->arg;
	pthread_mutex_lock(&arg->philo_mtx[philo->id - 1]);
	philo->time_start = get_time();
	philo->time_last_eat = philo->time_start;
	pthread_mutex_unlock(&arg->philo_mtx[philo->id - 1]);
	if (philo->id % 2 == 0
		|| (philo->id == arg->num_of_philo && arg->num_of_philo != 1))
	{
		think(philo, arg);
		usleep(100);
	}
	int		i = 0;
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
		i++;
	}
	return (NULL);
}

void	create_threads(t_arg *arg)
{
	long		i;

	i = 0;
	while (i < arg->num_of_philo)
	{
		if (pthread_create(&arg->philo[i].thread, NULL, routine_philo, &arg->philo[i]) != 0)
			error_func(ERROR_PTHREAD_CREATE, "create_threads_pthread_create", __LINE__);
		i++;
	}
	if (pthread_create(&arg->thread_monitor, NULL, monitor, arg) != 0)
		error_func(ERROR_PTHREAD_CREATE, "create_threads_pthread_create", __LINE__);
	return ;
}
