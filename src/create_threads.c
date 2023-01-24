/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:53:06 by yshimoda          #+#    #+#             */
/*   Updated: 2023/01/25 08:30:25 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// static void	*threadfunc(void *philo_void)
// {
// 	(char *)philo;
// 	return (NULL);
// }

static void	*routine_philo(void *philo_void)
{
	t_philo	*philo;

	philo = philo_void;
	if (philo->id % 2 == 0 || philo->id == philo->arg->num_of_philo)
		usleep(10);
	philo->last_eat_time = get_time();
	while (1)
	{
		pick_up_fork(philo, philo->arg);
		eat(philo, philo->arg);
		put_down_fork(philo, philo->arg);
		think(philo, philo->arg);
		
		// break ;
	}
	return (NULL);
}

void	create_threads(int argc, t_arg *arg)
{
	long	i;

	arg->start_time = get_time();
	if (argc == 6)
	{
		printf("%d\n", 6);
		return ;
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
		usleep(10);
	}
	return ;
}
