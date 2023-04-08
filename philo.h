#ifndef PHILO_H
# define PHILO_H
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_philos
{
	pthread_t		th;
	int				id;
	int				status;
	int				lft_fork_id;
	int				rgt_fork_id;
	int				n_eat;
	long long		time_init;
	long long		last_eat;
	struct s_data	*data;
}				t_philos;
 
typedef struct s_data
{
	int				n_philos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	t_philos		*philos;
	pthread_mutex_t	*forks;
}				t_data;


// long	ft_atoi(const char *str);
#endif