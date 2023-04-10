/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:19:19 by aankote           #+#    #+#             */
/*   Updated: 2023/04/10 03:02:00 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long get_current_time()
{
	struct timeval time;
	
	gettimeofday(&time, NULL);
	return(time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	*routine(void *arg)
{
	t_philos	*phil;

	phil = (t_philos *)arg;
	while (1)
	{
		pthread_mutex_lock(&phil->data->forks[phil->rgt_fork_id]);
		printf("%ldms philo %d  has taken a fork right\n", get_current_time() - phil->data->time_init, phil->id  + 1);
		pthread_mutex_lock(&phil->data->forks[phil->lft_fork_id]);
		printf("%ldms philo %d  has taken a fork left\n", get_current_time() - phil->data->time_init, phil->id  + 1);
		printf("%ldms philo %d  is eating\n", get_current_time() - phil->data->time_init, phil->id  + 1);
		phil->last_eat = get_current_time();
		my_usleep(phil->data->time_eat * 1000);
		pthread_mutex_unlock(&phil->data->forks[phil->lft_fork_id]);
		pthread_mutex_unlock(&phil->data->forks[phil->rgt_fork_id]);
		printf("%ldms philo %d  is sleeping\n", get_current_time() - phil->data->time_init, phil->id  + 1);
		my_usleep(phil->data->time_sleep * 1000);
		printf("%ldms philo %d  is thinking\n", get_current_time() - phil->data->time_init, phil->id  + 1);
	}	
	return (0);
}

t_data *data_init(char **av)
{
	int		i;
	t_data *data;

	i = 0;
	data = malloc(sizeof(t_data));
	data->n_philos = atoi(av[1]);
	data->philos = malloc(sizeof(t_philos) * data->n_philos);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philos);
	data->time_sleep = atoi(av[4]);
	data->time_eat = atoi(av[3]);
	data->time_die = atoi(av[2]);
	data->time_init = get_current_time();
	while (data->n_philos > i)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	return (data);
}

void creat_philos(t_data *data)
{
	int i;
	
	i = 0;
	while (data->n_philos > i)
	{
		data->philos[i].id = i;
		data->philos[i].data = data;
		data->philos[i].last_eat = data->time_init;
		data->philos[i].rgt_fork_id= i;
		if(i == data->n_philos - 1)
			data->philos[i].lft_fork_id = 0;
		else
			data->philos[i].lft_fork_id = (i + 1);
		pthread_create(&data->philos[i].th, NULL, routine, &data->philos[i]);
		usleep(100);
		i++;
	}
}

int main(int ac, char **av)
{
	t_data *data;
	int i;
	
	ac = 0;
	i = 0;
	data = data_init(av);
	creat_philos(data);
	dead(data);
	while (data->n_philos > i)
	{
		pthread_join(data->philos[i].th, NULL);
		i++;
	}
}
