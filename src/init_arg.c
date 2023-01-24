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

static void	init_philo_mutex(t_philo *philo)
{
//	if (pthread_mutex_init(philo->fork_right_m, NULL) != 0)
//		error_func(ERROR_MUTEX_INIT);
//	if (pthread_mutex_init(philo->fork_left_m, NULL) != 0)
//		error_func(ERROR_MUTEX_INIT);
	if (pthread_mutex_init(&philo->last_eat_time_m, NULL) != 0)
	{
		printf("%s\t%d\n", "init_philo_mutex_1", __LINE__);
		error_func(ERROR_MUTEX_INIT);
	}
	if (pthread_mutex_init(&philo->num_of_eaten_m, NULL) != 0)
	{
		printf("%s\t%d\n", "init_philo_mutex_2", __LINE__);
		error_func(ERROR_MUTEX_INIT);
	}
	return ;
}

static void	init_philo(t_philo *philo, t_arg *arg, int i)
{
	philo->arg = arg;
	if (i == MAX_PHILO - 1)
		philo->fork_left_m = &arg->fork_m[0];
	else
		philo->fork_left_m = &arg->fork_m[i + 1];
	philo->fork_right_m = &arg->fork_m[i];
	philo->id = i + 1;
	philo->num_of_eaten = 0;
	init_philo_mutex(philo);
	return ;
}

static void	init_arg_mutex(t_arg *arg)
{
	int		i;

	if (pthread_mutex_init(&(arg->dead_m), NULL) != 0)
	{
		printf("%s\t%d\n", "init_arg_mutex", __LINE__);
		error_func(ERROR_MUTEX_INIT);
	}
	if (pthread_mutex_init(&(arg->finish_m), NULL) != 0)
	{
		printf("%s\t%d\n", "init_arg_mutex", __LINE__);
		error_func(ERROR_MUTEX_INIT);
	}
	if (pthread_mutex_init(&(arg->write_mutex), NULL) != 0)
	{
		printf("%s\t%d\n", "init_arg_mutex", __LINE__);
		error_func(ERROR_MUTEX_INIT);
	}
	i = 0;
	while (i < MAX_PHILO)
	{
		if (pthread_mutex_init(&(arg->fork_m[i]), NULL) != 0)
		{
			printf("%s\t%d\n", "init_arg_mutex", __LINE__);
			error_func(ERROR_MUTEX_INIT);
		}
		i++;
	}
	return ;
}

void	init_arg(t_arg *arg)
{
	int		i;

	arg->dead = false;
	arg->finish = false;
	init_arg_mutex(arg);
	i = 0;
	while (i < MAX_PHILO)
	{
		init_philo(&arg->philo[i], arg, i);
		i++;
	}
	return ;
}
