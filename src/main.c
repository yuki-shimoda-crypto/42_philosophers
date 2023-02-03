/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:02:42 by fedora            #+#    #+#             */
/*   Updated: 2023/02/04 05:33:45 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char const *argv[])
{
	t_arg	arg;

	check_input(argc, argv, &arg);
	init_arg(&arg);
	create_threads(&arg);
	wait_close_threads(&arg);
	terminate_arg(&arg);
	return (0);
}
