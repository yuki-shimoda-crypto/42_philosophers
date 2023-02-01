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
	philo->arg = arg;
	philo->fork_left_mtx = &arg->fork_mtx[i];
	if (i == arg->num_of_philo - 1)
	{
		philo->fork_left_mtx = &arg->fork_mtx[0];
		philo->fork_right_mtx = &arg->fork_mtx[i];
	}
	else
		philo->fork_right_mtx = &arg->fork_mtx[i + 1];
	philo->id = i + 1;
	philo->num_of_eaten = 0;
	return ;
}

static void	init_arg_mutex(t_arg *arg)
{
	int		i;

	i = 0;
	while (i < arg->num_of_philo)
	{
		if (pthread_mutex_init(&arg->fork_mtx[i], NULL) != 0)
			error_func(ERROR_MUTEX_INIT, "init_arg_mutex", __LINE__);
		if (pthread_mutex_init(&arg->philo_mtx[i], NULL) != 0)
			error_func(ERROR_MUTEX_INIT, "init_arg_mutex", __LINE__);
		i++;
	}
	if (pthread_mutex_init(&arg->write_exit_mtx, NULL) != 0)
		error_func(ERROR_MUTEX_INIT, "init_arg_mutex", __LINE__);
	return ;
}

void	init_arg(t_arg *arg)
{
	int		i;

	arg->is_exit = false;
	init_arg_mutex(arg);
	i = 0;
	while (i < arg->num_of_philo)
	{
		init_philo(&arg->philo[i], arg, i);
		i++;
	}
	return ;
}
