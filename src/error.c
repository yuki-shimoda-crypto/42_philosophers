/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:39:35 by yshimoda          #+#    #+#             */
/*   Updated: 2023/01/23 14:26:49 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static const char	*get_error_message(int id)
{
	if (id == ERROR_FEW_ARG)
		return ("Error, too few arguments\n");
	if (id == ERROR_MANY_ARG)
		return ("Error, too many arguments\n");
	if (id == ERROR_ARG_INVALID)
		return ("Error, arguments is invalid\n");
	if (id == ERROR_MUTEX_INIT)
		return ("Error, failed to initialize mutex\n");
	if (id == ERROR_GET_TIME)
		return ("Error, gettimeofday is failed\n");
	if (id == ERROR_PTHREAD_CREATE)
		return ("Error, thread create is failed\n");
	if (id == ERROR_MUTEX_LOCK)
		return ("Error, mutex lock is failed\n");
	if (id == ERROR_MUTEX_UNLOCK)
		return ("Error, mutex unlock is failed\n");
	return ("Error\n");
}

void	error_func(int id)
{
	const char	*str;

	str = get_error_message(id);
	ft_putstr_fd(str, STDERR_FILENO);
	exit(EXIT_FAILURE);
	return ;
}
