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

static void	*routine_philo(void *philo_void)
{
	t_philo	*philo;
	int		i = 0;

	philo = philo_void;
	if (philo->id % 2 == 0 || philo->id == philo->arg->num_of_philo)
		usleep(100);
	philo->last_eat_time = get_time();
	while (1)
	{
		pick_up_fork(philo, philo->arg);
		usleep(100);
		eat(philo, philo->arg);
		put_down_fork(philo, philo->arg);
		usleep(100);
		philo_sleep(philo, philo->arg);
		usleep(100);
		think(philo, philo->arg);
		i++;
		if (i == 5)
		{
			printf("%s\n", "finish");
			break ;
		}
	}
	return (NULL);
}

void	create_threads(int argc, t_arg *arg)
{
	long	i;

	arg->start_time = get_time();
	if (argc == 6)
	{
		exit(EXIT_SUCCESS);
		// if (pthread_create(&arg->philo[i].thread, NULL, monitor, &arg->philo[i]) != 0)
		// {
		// }
	}
	i = 0;
	while (i < arg->num_of_philo)
	{
		if (pthread_create(&arg->philo[i].thread, NULL, routine_philo, &arg->philo[i]) != 0)
		{
			printf("%s\t%d\n", "create_threads_pthread_create", __LINE__);
			error_func(ERROR_PTHREAD_CREATE);
		}
		pthread_detach(arg->philo[i].thread);
		// usleep?
		i++;
		usleep(100);
	}
	return ;
}
