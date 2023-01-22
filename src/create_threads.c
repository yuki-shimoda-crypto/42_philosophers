/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:53:06 by yshimoda          #+#    #+#             */
/*   Updated: 2023/01/23 08:38:42 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*threadfunc(void *philo)
{
	(char *)philo;
	return (NULL);
}

void	create_threads(int argc, t_arg *arg)
{
	int	i;

	i = 0;
	if (argc == 6)
	{
		pthread_create(arg)
		/* code */
	}
	
	while (i < MAX_INPUT)
	{
		pthread_create(arg->philo[i].thread, NULL, threadfunc, &arg->philo[i]);
		i++;
	}
	return ;
}
