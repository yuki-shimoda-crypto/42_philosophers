/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:02:42 by fedora            #+#    #+#             */
/*   Updated: 2023/01/17 13:33:57y yshimoda         ###   ########.fr       */
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
		if (pthread_join(arg->philo[i].thread, NULL) != 0)
			error_func(ERROR_PTHREAD_JOIN, "wait_close_threads", __LINE__);
		i++;
	}
	// if (pthread_join(arg->thread_monitor, NULL) != 0)
	// 	error_func(ERROR_PTHREAD_JOIN, "wait_close_threads", __LINE__);
}

int main(int argc, char const *argv[])
{
	t_arg	arg;

	check_input(argc, argv, &arg);
	init_arg(&arg);
	create_threads(&arg);
	wait_close_threads(&arg);
	// terminate_arg(&arg);
	return (0);
}
