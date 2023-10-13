/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:34:26 by inwagner          #+#    #+#             */
/*   Updated: 2023/10/13 14:25:00 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ratatoui(char *str)
{
	unsigned int	number;
	int				i;

	i = 0;
	number = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	if (number > INT_MAX)
		return (-1);
	return ((int)number);
}

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

	time = get_time_in_usec();
	pthread_mutex_lock(&call_butler()->printer);
	if (!call_butler()->stop)
	{
		printf("%li %i ", time / 1000, philo->id + 1);
		if (status == DIED)
			printf("is dead\n");
		if (status == EATING)
			printf("is eating\n");
		if (status == SLEEPING)
			printf("is sleeping\n");
		if (status == THINKING)
			printf("is thinking\n");
		if (status == LEFT_HASHI)
			printf("has taken a fork\n");
		if (status == RIGHT_HASHI)
			printf("has taken a fork\n");
	}
	pthread_mutex_unlock(&call_butler()->printer);
	return (time);
}
