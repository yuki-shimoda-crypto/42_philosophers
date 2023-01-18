/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:56:39 by yshimoda          #+#    #+#             */
/*   Updated: 2023/01/18 20:57:53 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	init_philo(t_philo *philo, t_var *var, int i)
{
	philo->last_eat_time = var->start_time;
	philo->num_of_eaten = 0;
	pthread_mutex_init(&philo->m_last_eat_time, NULL);
	pthread_mutex_init(&philo->m_num_of_eaten, NULL);
	philo->right_fork = &var->forks[i];
	if (i == MAX_PHILO)
		philo->left_fork = &var->forks[0];
	else
		philo->left_fork = &var->forks[i + 1];
	return ;
}

void	init_var(t_var *var)
{
	int		i;

	gettimeofday(&var->start_time, NULL);
	i = 0;
	while (i < MAX_PHILO)
	{
		init_philo(&var->philo[i], var, i);
		i++;
	}
	while (i < MAX_PHILO)
	{
		printf("%i\t%p\n", i, &var->philo[i]);
		i++;
	}
	return ;
}
