/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:13:42 by yshimoda          #+#    #+#             */
/*   Updated: 2023/02/03 10:18:20 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	print_action(t_arg *arg, long timestamp, int *id, const char *action)
{
	if (pthread_mutex_lock(&arg->write_exit_mtx) != 0)
		error_func(ERROR_MUTEX_LOCK, "print_action", __LINE__);
	if (arg->is_exit)
	{
		if (pthread_mutex_unlock(&arg->write_exit_mtx) != 0)
			error_func(ERROR_MUTEX_UNLOCK, "print_action", __LINE__);
		return (false);
	}
	printf("%ld %d %s\n", timestamp, *id, action);
	pthread_mutex_unlock(&arg->write_exit_mtx);
	return (true);
}
