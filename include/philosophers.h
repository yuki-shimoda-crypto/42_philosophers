/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:54:10 by fedora            #+#    #+#             */
/*   Updated: 2023/01/23 09:02:45 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define MAX_PHILO 200

# define ERROR_FEW_ARG 0
# define ERROR_MANY_ARG 1
# define ERROR_ARG_INVALID 2
# define ERROR_MUTEX_INIT 3
# define ERROR_GET_TIME 4

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_mutex_t	*fork_left_m;
	pthread_mutex_t	*fork_right_m;
	int				id;
	struct timeval	last_eat_time;
	pthread_mutex_t	last_eat_time_m;
	int				num_of_eaten;
	pthread_mutex_t	num_of_eaten_m;
	pthread_t		thread;
}	t_philo;

typedef struct s_arg
{
	long				num_of_philo;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				num_of_must_eat;

	bool				dead;
	pthread_mutex_t		dead_m;
	bool				finish;
	pthread_mutex_t		finish_m;
	pthread_mutex_t		fork_m[MAX_PHILO];
	t_philo				philo[MAX_PHILO];
	struct timeval		start_time;
	pthread_mutex_t		write_mutex;
}	t_arg;

void		check_input(int argc, char const *argv[], t_arg *arg);
void		create_threads(t_arg *arg);
void		error_func(int id);
long		ft_atol(const char *str);
void		ft_putstr_fd(const char *s, int fd);
size_t		ft_strlen(const char *s);
void		init_arg(t_arg *arg);

#endif
