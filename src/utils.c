/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:13:42 by yshimoda          #+#    #+#             */
/*   Updated: 2023/02/03 20:23:06 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
