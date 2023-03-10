/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:06:13 by yshimoda          #+#    #+#             */
/*   Updated: 2023/02/07 20:17:42 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	check_arg_num(t_arg *arg, int argc)
{
	if (arg->num_of_philo < 1 || MAX_PHILO < arg->num_of_philo)
		return (error_func(ERROR_ARG_INVALID));
	if (arg->time_to_die < 1 || INT_MAX < arg->time_to_die)
		return (error_func(ERROR_ARG_INVALID));
	if (arg->time_to_eat < 1 || INT_MAX < arg->time_to_eat)
		return (error_func(ERROR_ARG_INVALID));
	if (arg->time_to_sleep < 1 || INT_MAX < arg->time_to_sleep)
		return (error_func(ERROR_ARG_INVALID));
	if (argc == 6 && \
		(arg->num_of_must_eat < 1 || INT_MAX < arg->num_of_must_eat))
		return (error_func(ERROR_ARG_INVALID));
	return (true);
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

static bool	check_isnum(char const *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][0] == '\0')
			return (error_func(ERROR_ARG_INVALID));
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (error_func(ERROR_ARG_INVALID));
			j++;
		}
		i++;
	}
	return (true);
}

static inline bool	check_argc(int argc)
{
	if (argc < 5)
		return (error_func(ERROR_FEW_ARG));
	else if (6 < argc)
		return (error_func(ERROR_MANY_ARG));
	return (true);
}

bool	check_input(int argc, char const *argv[], t_arg *arg)
{
	if (!check_argc(argc))
		return (false);
	if (!check_isnum(argv))
		return (false);
	input_arg(argc, argv, arg);
	if (!check_arg_num(arg, argc))
		return (false);
	return (true);
}
