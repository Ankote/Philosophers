/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:19:19 by aankote           #+#    #+#             */
/*   Updated: 2023/04/08 13:54:19 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philos	*phil;

	phil = (t_philos *)arg;
	while (1)
	{
		printf("philo %d take a fork\n", phil->id);
		printf("philo %d take a fork\n", phil->id);
		printf("philo %d is eating\n", phil->id);
		usleep(phil->data->time_eat * 1000);
		printf("philo %d is sleeping\n", phil->id);
		usleep(phil->data->time_sleep * 1000);
		printf("philo %d is thinking\n", phil->id);
		
	}	
	return (0);
}

int main(int ac, char **av)
{
	ac = 0;
	int		i;
	t_data *data;

	i = 0;
	data = malloc(sizeof(t_data));
	data->n_philos = atoi(av[1]);
	data->philos = malloc(sizeof(t_philos) * data->n_philos);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philos);
	i = 0;
	while (data->n_philos > i)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	i = 0;
	while (data->n_philos > i)
	{
		data->philos[i].id = i;
		data->philos[i].data = data;
		data->philos[i].data->time_sleep = atoi(av[4]);
		data->philos[i].data->time_eat = atoi(av[3]);
		data->philos[i].lft_fork_id = i;
		data->philos[i].rgt_fork_id = ((i + 1) % data->n_philos);
		pthread_create(&data->philos[i].th, NULL, routine, &data->philos[i]);
		usleep(100);
		i++;
	}
	i = 0;
	while (data->n_philos)
	{
		pthread_join(data->philos[i].th, NULL);
		i++;
	}
}

// #include <stdio.h>
// #include <sys/time.h>

// int main() {
//     struct timeval start, end;
//     long seconds, microseconds;

//     gettimeofday(&start, NULL);

//     // Code for the first event
// 	usleep(1000000);
//     gettimeofday(&end, NULL);

//     seconds = end.tv_sec - start.tv_sec;
//     microseconds = end.tv_usec - start.tv_usec;
//     //long elapsed_time = (seconds * 1000000) + microseconds;

//     printf("Elapsed time: %ld microseconds\n", seconds * 1000);
//     return 0;
// }
