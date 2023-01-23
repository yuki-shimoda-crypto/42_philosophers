/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:53:06 by yshimoda          #+#    #+#             */
/*   Updated: 2023/01/23 09:15:08 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*threadfunc(void *philo)
{
	(char *)philo;
	return (NULL);
}

void	*routine_philo(void *philo_void)
{
	t_philo	*philo;

	philo = philo_void;
	if (gettimeofday(&philo->last_eat_time, NULL) != 0)
		error_func(ERROR_GET_TIME);
	while (1)
	{
		
	}
	
}

void	create_threads(int argc, t_arg *arg)
{
	int	i;

	gettimeofday(&arg->start_time, NULL);
	if (argc == 6)
	{
		pthread_create(arg);
	}
	i = 0;
	while (i < MAX_INPUT)
	{
		pthread_create(arg->philo[i].thread, NULL, threadfunc, &arg->philo[i]);
		pthread_create(arg->philo[i].thread, NULL, routine_philo, &arg->philo[i]);
		i++;
	}
	return ;
}
