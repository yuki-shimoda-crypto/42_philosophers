/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:54:10 by fedora            #+#    #+#             */
/*   Updated: 2023/02/04 19:30:11 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define MAX_PHILO 200

# define ERROR_FEW_ARG "Error, too few arguments\n"
# define ERROR_MANY_ARG "Error, too many arguments\n"
# define ERROR_ARG_INVALID "Error, arguments is invalid\n"

# define TYPE_TAKE_FORK "has taken a fork"
# define TYPE_EAT "is eating"
# define TYPE_SLEEP "is sleeping"
# define TYPE_THINK "is thinking"
# define TYPE_DIE "died"

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	struct s_arg	*arg;
	pthread_mutex_t	*fork_left_mtx;
	pthread_mutex_t	*fork_right_mtx;
	int				id;
	int				num_of_eaten;
	time_t			time_end_take_fork;
	time_t			time_last_eat;
	time_t			time_start;
	pthread_t		thread;
}	t_philo;

typedef struct s_arg
{
	long				num_of_philo;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				num_of_must_eat;

	int					dead_num;
	bool				is_exit;
	t_philo				philo[MAX_PHILO];
	time_t				time_start;
	pthread_mutex_t		fork_mtx[MAX_PHILO];
	pthread_mutex_t		philo_mtx[MAX_PHILO];
	pthread_mutex_t		write_exit_mtx;
	pthread_t			thread_monitor;
}	t_arg;

// utils_time
time_t		calc_time(long now_time, long start_time);
time_t		calc_elapsed_time(long *start_time);
time_t		get_time(void);

// libft function
long		ft_atol(const char *str);
int			ft_isdigit(int c);
void		ft_putstr_fd(const char *s, int fd);
size_t		ft_strlen(const char *s);

// philo function
bool		eat_philo(t_philo *philo, t_arg *arg);
bool		sleep_philo(t_philo *philo, t_arg *arg);
bool		think_philo(t_philo *philo, t_arg *arg);

void		check_input(int argc, char const *argv[], t_arg *arg);
void		create_threads(t_arg *arg);
void		error_func(const char *str);
void		init_arg(t_arg *arg);
void		*monitor(void *arg_void);
bool		print_action(t_arg *arg, long timestamp,
				int *id, const char *action);
void		terminate_arg(t_arg *arg);
void		wait_close_threads(t_arg *arg);

#endif
