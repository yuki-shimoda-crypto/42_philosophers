# Philosophers

## Flow
1. check input
	1. argc is 5 or 6
		- if argc == 5 LONG_MAX
	1. isnum
	1. num_of_philo is between 1 and 200
	1. time_to_die is greater than 1
	1. time_to_eat is greater than 1
	1. time_to_sleep is greater than 1
		- if argc is 6, num_of_must_eat is greater than 1
1. init_var
	- input time
1. 

## Struct
###  Philosophers
```c
typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	struct timeval	last_eat_time;
	pthread_mutex_t	last_eat_time_m;
	int				num_of_eaten;
	pthread_mutex_t	num_of_eaten_m;
	pthread_mutex_t	*left_fork_m;
	pthread_mutex_t	*right_fork_m;
}	t_philo;
```

### argument
```c
typedef struct s_arg
{
	bool				dead;
	pthread_mutex_t		dead_m;
	bool				finish;
	pthread_mutex_t		finish_m;
	pthread_mutex_t		fork_m[MAX_PHILO];
	t_philo				philo[MAX_PHILO];
	struct timeval		start_time;
	long				num_of_philo;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				num_of_must_eat;

	pthread_mutex_t			write_mutex;
	// int						stop;
}	t_arg;
```

## define
```c
# define MAX_PHILO 200
```
