/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:54:10 by fedora            #+#    #+#             */
/*   Updated: 2023/01/16 20:35:14 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define NUM_PHILOSOPHERS 200

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t	
}		t_philo;

typedef struct s_var
{
	t_philo		philo[NUM_PHILOSOPHERS];
	t_philo		forks[NUM_PHILOSOPHERS];
}		t_var;


#endif
