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


int main(int argc, char const *argv[])
{
	t_arg	arg;
	t_var	var;

	check_input(argc, argv, &arg);
	init_var(&var);
	ft_thread_create(&var);
	return (0);
}