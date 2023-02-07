/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:56:39 by yshimoda          #+#    #+#             */
/*   Updated: 2023/02/07 21:31:44 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	init_philo(t_philo *philo, t_arg *arg, int i)
{
	philo->arg = arg;
//	if (i == arg->num_of_philo - 1)
//	{
//		if (i % 2 == 0)
//		{
//			philo->fork_right_mtx = &arg->fork_mtx[i];
//			philo->fork_left_mtx = &arg->fork_mtx[0];
//		}
//		else
//		{
//			philo->fork_right_mtx = &arg->fork_mtx[0];
//			philo->fork_left_mtx = &arg->fork_mtx[i];
//		}
//	}
//	else
//	{
//		if (i % 2 == 0)
//		{
//			philo->fork_right_mtx = &arg->fork_mtx[i];
//			philo->fork_left_mtx = &arg->fork_mtx[i + 1];
//		}
//		else
//		{
//			philo->fork_right_mtx = &arg->fork_mtx[i + 1];
//			philo->fork_left_mtx = &arg->fork_mtx[i];
//		}
//	}
//

	if (i % 2 == 0)
	{
		philo->fork_right_mtx = &arg->fork_mtx[i];
		if (i == arg->num_of_philo - 1)
			philo->fork_left_mtx = &arg->fork_mtx[0];
		else
			philo->fork_left_mtx = &arg->fork_mtx[i + 1];
	}
	else
	{
		if (i == arg->num_of_philo - 1)
			philo->fork_right_mtx = &arg->fork_mtx[0];
		else
			philo->fork_right_mtx = &arg->fork_mtx[i + 1];
		philo->fork_left_mtx = &arg->fork_mtx[i];
	}

//	philo->fork_left_mtx = &arg->fork_mtx[i];
//	if (i == arg->num_of_philo - 1)
//	{
//		philo->fork_left_mtx = &arg->fork_mtx[0];
//		philo->fork_right_mtx = &arg->fork_mtx[i];
//	}
//	else
//		philo->fork_right_mtx = &arg->fork_mtx[i + 1];
//
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
		pthread_mutex_init(&arg->fork_mtx[i], NULL);
		pthread_mutex_init(&arg->philo_mtx[i], NULL);
		i++;
	}
	pthread_mutex_init(&arg->write_exit_mtx, NULL);
	return ;
}

void	init_arg(t_arg *arg)
{
	int		i;

	arg->dead_num = 0;
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
