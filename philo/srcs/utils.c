/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:34:26 by inwagner          #+#    #+#             */
/*   Updated: 2023/10/12 15:17:32 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	get_time_in_usec(void)
{
	struct timeval		tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

int	is_dead(t_plate *philo)
{
	return (philo->last_meal + call_butler()->time_to_die < get_time_in_usec());
}

time_t	print_status(t_plate *philo, int status)
{
	time_t	time;

	if (call_butler()->stop)
		return (0);
	time = get_time_in_usec();
	pthread_mutex_lock(&call_butler()->printer);
	printf("%li\t%i ", time / 1000, philo->id + 1);
	if (status == DIED)
		printf("is dead.\n");
	if (status == EATING)
		printf("is eating.\n");
	if (status == SLEEPING)
		printf("is sleeping.\n");
	if (status == THINKING)
		printf("is thinking.\n");
	if (status == LEFT_HASHI)
		printf("has taken a fork.\n");
	if (status == RIGHT_HASHI)
		printf("has taken a fork.\n");
	pthread_mutex_unlock(&call_butler()->printer);
	return (time);
}
