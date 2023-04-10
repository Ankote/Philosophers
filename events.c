/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:26:44 by aankote           #+#    #+#             */
/*   Updated: 2023/04/10 00:28:40 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void dead(t_data *data)
{
    int i;
    
    while(1)
    {
        i = 0;
        while(data->n_philos > i)
        {
            if(get_current_time() - data->philos[i].last_eat > data->time_die)
            {
                printf("%ld time \t time to die: %ld\n", get_current_time() - data->philos[i].last_eat, data->time_die);
		        printf("%ldms philo %d  died\n", get_current_time() - data->philos[i].data->time_init, data->philos[i].id + 1);
                exit(0);
            }
            i++;   
        }
    }
}