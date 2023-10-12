/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_eat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:30:40 by inwagner          #+#    #+#             */
/*   Updated: 2023/10/11 21:19:54 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	drop_hashis(t_plate *philo, int left, int right)
{
	if (philo->holding_hashis == 2)
	{
		pthread_mutex_unlock(&philo->hashi[right]);
		philo->holding_hashis--;
	}
	if (philo->holding_hashis == 1)
	{
		pthread_mutex_unlock(&philo->hashi[left]);
		philo->holding_hashis--;
	}
}

int	philo_eating(t_plate *philo)
{
	if (philo->end_dinner)
		return (0);
	philo->last_meal = print_status(philo, EATING);
	usleep(call_butler()->time_to_eat);
	if (++philo->total_ate == call_butler()->total_must_eat)
	{
		call_butler()->stop = TRUE;
		printf("hehehe\n");
	}
	drop_hashis(philo, philo->hashis[0], philo->hashis[1]);
	return (0);
}
