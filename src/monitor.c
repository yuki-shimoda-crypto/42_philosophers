/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:04:23 by yshimoda          #+#    #+#             */
/*   Updated: 2023/02/03 20:39:35 by yshimoda         ###   ########.fr       */
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
		if (arg->time_to_die < calc_elapsed_time(&arg->philo[i].time_last_eat))
		{
			pthread_mutex_unlock(&arg->philo_mtx[i]);
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

void	*monitor(void *arg_void)
{
	t_arg	*arg;

	arg = arg_void;
	usleep(arg->time_to_die / 2);
	while (1)
	{
		if (is_philo_starve(arg))
		{
			pthread_mutex_lock(&arg->write_exit_mtx);
			printf("%ld %d %s\n",
				calc_elapsed_time(&arg->philo[arg->dead_num].time_start),
				arg->dead_num + 1, TYPE_DIE);
			arg->is_exit = true;
			pthread_mutex_unlock(&arg->write_exit_mtx);
			break ;
		}
		if (is_num_of_eat_reached(arg))
		{
			pthread_mutex_lock(&arg->write_exit_mtx);
			arg->is_exit = true;
			pthread_mutex_unlock(&arg->write_exit_mtx);
			break ;
		}
	}
	return (NULL);
}
