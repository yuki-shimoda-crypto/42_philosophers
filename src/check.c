/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:06:13 by yshimoda          #+#    #+#             */
/*   Updated: 2023/01/17 23:04:28by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	check_arg_num(t_arg *arg)
{
	if (arg->num_of_philo < 2 || MAX_PHILO < arg->num_of_philo)
	{
		printf("%s\t%d\n", "check_arg_num", __LINE__);
		error_func(ERROR_ARG_INVALID);
	}
	if (arg->time_to_die < 1)
	{
		printf("%s\t%d\n", "check_arg_num", __LINE__);
		error_func(ERROR_ARG_INVALID);
	}
	if (arg->time_to_eat < 1)
	{
		printf("%s\t%d\n", "check_arg_num", __LINE__);
		error_func(ERROR_ARG_INVALID);
	}
	if (arg->time_to_sleep < 1)
	{
		printf("%s\t%d\n", "check_arg_num", __LINE__);
		error_func(ERROR_ARG_INVALID);
	}
	if (arg->num_of_must_eat < 1)
	{
		printf("%s\t%d\n", "check_arg_num", __LINE__);
		error_func(ERROR_ARG_INVALID);
	}
	return ;
}

static void	input_arg(int argc, char const *argv[], t_arg *arg)
{
	arg->num_of_philo = ft_atol(argv[1]);
	arg->time_to_die = ft_atol(argv[2]);
	arg->time_to_eat = ft_atol(argv[3]);
	arg->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		arg->num_of_must_eat = ft_atol(argv[5]);
	else
		arg->num_of_must_eat = LONG_MAX;
	return ;
}

static void	check_isnum(char const *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][0] == '\0')
		{
			printf("%s\t%d\n", "check_is_num", __LINE__);
			error_func(ERROR_ARG_INVALID);
		}
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				printf("%s\t%d\n", "check_is_num", __LINE__);
				error_func(ERROR_ARG_INVALID);
			}
			j++;
		}
		i++;
	}
}

static void	check_argc(int argc)
{
	if (argc < 5)
	{
		printf("%s\t%d\n", "check_argc", __LINE__);
		error_func(ERROR_FEW_ARG);
	}
	else if (6 < argc)
		error_func(ERROR_MANY_ARG, __func__, __LINE__);
	return ;
}

void	check_input(int argc, char const *argv[], t_arg *arg)
{
	check_argc(argc);
	check_isnum(argv);
	input_arg(argc, argv, arg);
	check_arg_num(arg);
	return ;
}
