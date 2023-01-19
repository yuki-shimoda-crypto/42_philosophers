/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:44:08 by yshimoda          #+#    #+#             */
/*   Updated: 2023/01/19 13:34:37 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_arg
{
	long		num_of_philo;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		num_of_must_eat;
}	t_arg;

void	input(t_arg *arg, const char **argv, int argc)
{
	arg->num_of_philo = atoi(argv[1]);
	arg->time_to_die = atoi(argv[2]);
	arg->time_to_eat = atoi(argv[3]);
	arg->time_to_sleep = atoi(argv[4]);
	if (argc == 5)
		arg->num_of_must_eat = INT_MAX;
	else
		arg->num_of_must_eat = atoi(argv[5]);
}

int main(int argc, char const *argv[])
{
	t_arg	arg;

	if (argc != 5 && argc != 6)
		return (1);
	input(&arg, argv, argc);
	printf("%ld\n", arg.num_of_philo);
	printf("%ld\n", arg.time_to_die);
	printf("%ld\n", arg.time_to_eat);
	printf("%ld\n", arg.time_to_sleep);
	printf("%ld\n", arg.num_of_must_eat);
	return 0;
}

