/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:53:06 by yshimoda          #+#    #+#             */
/*   Updated: 2023/01/23 04:46:32 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*threadfunc(void *philo)
{
	(char *)philo;
	return (NULL);
}

void	ft_thread_create(t_arg *arg)
{
	int	i;

	i = 0;
	while (i < MAX_INPUT)
	{
		pthread_create(arg->philo[i].thread, NULL, threadfunc, &arg->philo[i]);
		i++;
	}
	return ;
}
