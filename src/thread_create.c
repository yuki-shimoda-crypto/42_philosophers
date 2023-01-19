/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:53:06 by yshimoda          #+#    #+#             */
/*   Updated: 2023/01/19 06:14:07 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*threadfunc(void *philo)
{
	(char *)philo;
	return (NULL);
}

void	ft_thread_create(t_var *var)
{
	int	i;

	i = 0;
	while (i < MAX_INPUT)
	{
		pthread_create(var->philo[i].thread, NULL, threadfunc, &var->philo[i]);
		i++;
	}
	return ;
}
