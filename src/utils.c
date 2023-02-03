/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:13:42 by yshimoda          #+#    #+#             */
/*   Updated: 2023/02/04 03:51:44 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	terminate_arg(t_arg *arg)
{
	int	i;

	i = 0;
	while (i < arg->num_of_philo)
	{
		pthread_mutex_destroy(&arg->fork_mtx[i]);
		pthread_mutex_destroy(&arg->philo_mtx[i]);
		i++;
	}
	pthread_mutex_destroy(&arg->write_exit_mtx);
}

void	wait_close_threads(t_arg *arg)
{
	int		i;

	i = 0;
	while (i < arg->num_of_philo)
	{
		pthread_join(arg->philo[i].thread, NULL);
		i++;
	}
	pthread_join(arg->thread_monitor, NULL);
}

bool	print_action(t_arg *arg, long timestamp, int *id, const char *action)
{
	pthread_mutex_lock(&arg->write_exit_mtx);
	if (arg->is_exit)
	{
		pthread_mutex_unlock(&arg->write_exit_mtx);
		return (false);
	}
	printf("%ld %d %s\n", timestamp, *id, action);
	pthread_mutex_unlock(&arg->write_exit_mtx);
	return (true);
}
