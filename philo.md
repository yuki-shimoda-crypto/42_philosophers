# Philosophers

## Flow
1. check input
	1. argc is 5 or 6
	1. isnum
	1. num_of_philo is between 2 and 200
	1. time_to_die is greater than 1
	1. time_to_eat is greater than 1
	1. time_to_sleep is greater than 1
		- if argc is 5, num_of_must_eat is LONG_MAX
		- if argc is 6, num_of_must_eat is greater than 1
1. init_var
	- input input_args
	- input time
1. create_threads
	1. if num_of_must_eat != 0 (argc == 6) create observer
	1. create philo threads
1. destroy mutex


## define
```c
# define MAX_PHILO 200
```

## Struct
###  Philosophers
```c
typedef struct s_philo
{
	pthread_mutex_t	*fork_left_m;
	pthread_mutex_t	*fork_right_m;
	int				id;
	struct timeval	last_eat_time;
	pthread_mutex_t	last_eat_time_m;
	int				num_of_eaten;
	pthread_mutex_t	num_of_eaten_m;
	pthread_t		thread;
}	t_philo;
```

### argument
```c
typedef struct s_arg
{
	long				num_of_philo;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				num_of_must_eat;

	bool				dead;
	pthread_mutex_t		dead_m;
	bool				finish;
	pthread_mutex_t		finish_m;
	pthread_mutex_t		fork_m[MAX_PHILO];
	t_philo				philo[MAX_PHILO];
	struct timeval		start_time;
	pthread_mutex_t		write_mutex;
}	t_arg;
```
