/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:54:10 by fedora            #+#    #+#             */
/*   Updated: 2023/01/18 00:35:39 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define MAX_PHILO 200

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo
{
	struct timeval	tv;
}		t_philo;

typedef struct s_var
{
	t_philo				philo[MAX_PHILO];
	pthread_mutex_t		forks[MAX_PHILO];
}		t_var;

typedef struct s_arg
{
	long		num_of_philo;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		num_of_must_eat;
}		t_arg;

void		check_input(int argc, char const *argv[], t_arg *arg);
void		error_func(const char *str);
long		ft_atol(const char *str);
void		ft_putstr_fd(const char *s, int fd);
size_t		ft_strlen(const char *s);

#endif
