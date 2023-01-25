/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:20:19 by yshimoda          #+#    #+#             */
/*   Updated: 2023/01/25 18:10:12 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	get_time(void)
{
	struct timeval	timeval;

	if (gettimeofday(&timeval, NULL) != 0)
		error_func(ERROR_GET_TIME, __func__, __LINE__);
	return (timeval.tv_sec * 1000 + timeval.tv_usec / 1000);
}

long	calc_time(long now_time, long start_time)
{
	return (now_time - start_time);
}
