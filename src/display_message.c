/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:39:54 by yshimoda          #+#    #+#             */
/*   Updated: 2023/01/23 19:26:45y yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	display_message(int id, long time_stamp, long philo_id, t_arg *arg)
{
	if (pthread_mutex_lock(&arg->write_mutex) != 0)
	{
		printf("%s\t%d\n", "display_message_pthread_mutex_lock", __LINE__);
		error_func(ERROR_MUTEX_LOCK);
	}
	if (id == TYPE_PUT_FORK)
		printf("%ld\t%ld has taken a fork\n", time_stamp, philo_id);
	else if (id == TYPE_EAT)
		printf("%ld\t%ld is eating\n", time_stamp, philo_id);
	else if (id == TYPE_SLEEP)
		printf("%ld\t%ld is sleeping\n", time_stamp, philo_id);
	else if (id == TYPE_THINK)
		printf("%ld\t%ld is thinking\n", time_stamp, philo_id);
	else if (id == TYPE_DIE)
		printf("%ld\t%ld died\n", time_stamp, philo_id);
	if (pthread_mutex_unlock(&arg->write_mutex) != 0)
	{
	 	printf("%s\t%d\n", "display_message_pthread_mutex_lock", __LINE__);
	 	error_func(ERROR_MUTEX_UNLOCK);
	}
	return ;
}
