/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:39:35 by yshimoda          #+#    #+#             */
/*   Updated: 2023/02/02 03:57:15 by yshimoda         ###   ########.fr       */
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
	if (id == ERROR_PTHREAD_JOIN)
		return ("Error, mutex join is failed\n");
	return ("Error\n");
}

inline void	error_func(int id, const char *str, int line)
{
	// remove func
	printf("%s\t%d\n", str, line);

	ft_putstr_fd(get_error_message(id), STDERR_FILENO);
	exit(EXIT_FAILURE);
	return ;
}
