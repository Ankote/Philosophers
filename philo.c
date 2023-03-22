/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:19:19 by aankote           #+#    #+#             */
/*   Updated: 2023/03/20 17:28:32 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
int i = 0;
void* routine()
{
    while(i++ < 10)
        i ++;
    printf("%d\n", i);
    sleep(2);
    while(i++ < 20)
        i ++;
     printf("%d\n", i);
    return(0);
}


int main()
{
    pthread_t t1;
    pthread_t t2;
    pthread_t t3;
    pthread_t t4;
    pthread_create(&t1, NULL, &routine, NULL);
    pthread_create(&t2, NULL, &routine, NULL);
    pthread_create(&t3, NULL, &routine, NULL);
    pthread_create(&t4, NULL, &routine, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    // pthread_join(t2, NULL);
    return (0);
}