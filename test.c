/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:44:08 by yshimoda          #+#    #+#             */
/*   Updated: 2023/02/01 13:51:47 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

// typedef struct s_arg
// {
// 	long		num_of_philo;
// 	long		time_to_die;
// 	long		time_to_eat;
// 	long		time_to_sleep;
// 	long		num_of_must_eat;
// }	t_arg;
// 
// void	input(t_arg *arg, const char **argv, int argc)
// {
// 	arg->num_of_philo = atoi(argv[1]);
// 	arg->time_to_die = atoi(argv[2]);
// 	arg->time_to_eat = atoi(argv[3]);
// 	arg->time_to_sleep = atoi(argv[4]);
// 	if (argc == 5)
// 		arg->num_of_must_eat = INT_MAX;
// 	else
// 		arg->num_of_must_eat = atoi(argv[5]);
// }
// 
// int main(int argc, char const *argv[])
// {
// 	t_arg	arg;
// 
// 	if (argc != 5 && argc != 6)
// 		return (1);
// 	input(&arg, argv, argc);
// 	printf("%ld\n", arg.num_of_philo);
// 	printf("%ld\n", arg.time_to_die);
// 	printf("%ld\n", arg.time_to_eat);
// 	printf("%ld\n", arg.time_to_sleep);
// 	printf("%ld\n", arg.num_of_must_eat);
// 	return 0;
// }

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>

// int main(void)
// {
// 	struct timeval	start;
// 	struct timeval	last;
// 	pthread_mutex_t		one;
// 	bool				eat;
// 
// 	gettimeofday(&start, null);
// 	usleep(1900);
// 	gettimeofday(&last, null);
// 	printf("%ld\n", start.tv_sec);
// 	printf("%d\n", start.tv_usec);
// 	printf("%ld\n", last.tv_sec);
// 	printf("%d\n", last.tv_usec);
// 	printf("%ld\n", (last.tv_sec - start.tv_sec) * 1000 + (last.tv_usec - start.tv_usec) / 1000);
// 	printf("%s\t%d\n", "create_threads", __line__);
// 	eat = false;
// 	pthread_mutex_init(&one, null);
// 	pthread_mutex_lock(&one);
// 	if (eat)
// 		pthread_mutex_unlock(&one);
// 	if (pthread_mutex_lock(&one) != 0)
// 		printf("%s\n", "error");
// 	return (0);
// }

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	*fork_left_mtx;
	pthread_mutex_t	*fork_right_mtx;
}	t_philo;

typedef struct s_arg
{
	bool				eating;
	pthread_mutex_t		fork_m[2];
	pthread_mutex_t		write_m;
	struct s_philo		philo[2];
}	t_arg;

void	*eat(void *philo_void)
{
	t_philo		*philo;

	philo = (t_philo *)philo_void;
	while (1)
	{
		pthread_mutex_lock(&philo->fork_left_mtx);
		if ()
			return ();
		pthread_mutex_unlock(&philo->fork_left_mtx);
		printf("%d\n", philo->id);
		pthread_mutex_lock(&philo->fork_right_mtx);
		pthread_mutex_unlock(&philo->fork_right_mtx);
	}
	return (NULL);
}

int main(void)
{
	int					i;
	t_arg				arg;

	arg.eating = false;
	for (int i = 0; i < 2; i++)
		pthread_mutex_init(&arg.fork_m[i], NULL);
	pthread_mutex_init(&arg.write_m, NULL);
	i = 0;
	while (i < 2)
	{
		arg.philo[i].fork_right_mtx = &arg.fork_m[i % 2];
		arg.philo[i].fork_left_mtx = &arg.fork_m[(i + 1) % 2];
		arg.philo[i].id = i + 1;
		i++;
	}
	i = 0;
	while (i < 2)
	{
		pthread_create(&arg.philo[i].thread, NULL, eat, arg.philo);
		usleep(100);
		i++;
	}
	return (0);
}
