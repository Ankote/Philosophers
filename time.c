/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 00:58:43 by aankote           #+#    #+#             */
/*   Updated: 2023/04/10 00:39:55 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	gettime(struct timeval *start1)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	return ((get_current_time()
			- (start1->tv_sec * 1000 + start1->tv_usec / 1000)));
}

void	my_usleep(long time)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	while (gettime(&start) < time / 1000)
		usleep(100);
}

