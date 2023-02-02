/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:20:19 by yshimoda          #+#    #+#             */
/*   Updated: 2023/02/02 19:43:14 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

inline long	get_time(void)
{
	struct timeval	timeval;

	if (gettimeofday(&timeval, NULL) != 0)
		error_func(ERROR_GET_TIME, __func__, __LINE__);
	return (timeval.tv_sec * 1000 + timeval.tv_usec / 1000);
}

inline long	calc_elapsed_time(long start_time)
{
	struct timeval	timeval;

	gettimeofday(&timeval, NULL);
	return (timeval.tv_sec * 1000 + timeval.tv_usec / 1000 - start_time);
}
