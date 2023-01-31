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

// static void	*threadfunc(void *philo_void)
// {
// 	(char *)philo;
// 	return (NULL);
// }

// bool	is_hungry()
// {
// }

// static bool	can_continue(t_arg *arg)
// {
// }

// static void	*monitor(void *monitor_void)
// {
// 	t_monitor	*monitor;
// 	bool		is_continue;
// 	// int			i;
	
// 	monitor = monitor_void;
// 	is_continue = true;
// 	// i = 0;
// 	// while (is_continue)
// 	// {
// 	// 	is_continue = can_continue(monitor->arg);
// 	// }
// 	return (NULL);
// }

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

	philo = philo_void;
	if (philo->id % 2 == 0 || philo->id == philo->arg->num_of_philo)
	{
		think(philo, philo->arg);
		usleep(100);
	}
	philo->time_start = get_time();
	philo->time_last_eat = get_time();
	while (1)
	{
		if (!pick_up_fork(philo, philo->arg))
			break ;
		pick_up_fork(philo, philo->arg);
		eat(philo, philo->arg);
		put_down_fork(philo, philo->arg);
		philo_sleep(philo, philo->arg);
		think(philo, philo->arg);
	}
	return (NULL);
}

void	create_threads(int argc, t_arg *arg)
{
	long	i;

	if (argc == 6)
	{
		exit(EXIT_SUCCESS);
	//	if (pthread_create(&arg->philo[i].thread, NULL, monitor, &arg->philo[i]) != 0)
	//	{
	//	}
	}
	i = 0;
	while (i < arg->num_of_philo)
	{
		if (pthread_create(&arg->philo[i].thread, NULL, routine_philo, &arg->philo[i]) != 0)
			error_func(ERROR_PTHREAD_CREATE, "create_threads_pthread_create", __LINE__);
		pthread_detach(arg->philo[i].thread);
		// usleep?
		i++;
		usleep(100);
	}
	return ;
}
