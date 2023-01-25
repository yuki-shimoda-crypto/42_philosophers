/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:02:42 by fedora            #+#    #+#             */
/*   Updated: 2023/01/17 13:33:57y yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	wait_close_threads(t_arg *arg)
{
	int		i;

	i = 0;
	while (i < arg->num_of_philo)
	{
		pthread_join(arg->philo[i].thread, NULL);
		i++;
	}
}

int main(int argc, char const *argv[])
{
	t_arg	arg;

	check_input(argc, argv, &arg);
	init_arg(&arg);
	create_threads(argc, &arg);
	wait_close_threads(&arg);
	return (0);
}
