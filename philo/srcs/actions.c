/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:42:16 by inwagner          #+#    #+#             */
/*   Updated: 2023/10/13 12:00:40 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	hold_hashis(t_plate *philo, int left, int right)
{
	if (!philo->end_dinner && !philo->holding_hashis)
	{
		pthread_mutex_lock(&philo->hashi[left]);
		print_status(philo, LEFT_HASHI);
		philo->holding_hashis++;
	}
	if (!philo->end_dinner && philo->holding_hashis == 1 && \
		call_butler()->total_philos > 1)
	{
		pthread_mutex_lock(&philo->hashi[right]);
		print_status(philo, RIGHT_HASHI);
		philo->holding_hashis++;
	}
	return (0);
}

static int	drop_hashis(t_plate *philo, int left, int right)
{
	if (philo->holding_hashis == 2)
	{
		pthread_mutex_unlock(&philo->hashi[right]);
		philo->holding_hashis--;
	}
	if (philo->holding_hashis == 1 && \
		call_butler()->total_philos > 1)
	{
		pthread_mutex_unlock(&philo->hashi[left]);
		philo->holding_hashis--;
	}
	return (0);
}

int	philo_thinking(t_plate *philo)
{
	if (philo->end_dinner)
		return (0);
	print_status(philo, THINKING);
	return (hold_hashis(philo, philo->hashis[0], philo->hashis[1]));
}

int	philo_eating(t_plate *philo)
{
	if (philo->end_dinner)
		return (drop_hashis(philo, philo->hashis[0], philo->hashis[1]));
	if (philo->holding_hashis == 2)
	{
		philo->last_meal = print_status(philo, EATING);
		usleep(call_butler()->time_to_eat);
		if (++philo->total_ate == call_butler()->total_must_eat)
		{
			call_butler()->stop = TRUE;
			printf("Comeu tudo %i\n", philo->id);
		}
		return (drop_hashis(philo, philo->hashis[0], philo->hashis[1]));
	}
	drop_hashis(philo, philo->hashis[0], philo->hashis[1]);
	usleep(call_butler()->time_to_die + 1000);
	return (1);
}

int	philo_sleeping(t_plate *philo)
{
	if (philo->end_dinner)
		return (0);
	print_status(philo, SLEEPING);
	usleep(call_butler()->time_to_sleep);
	return (0);
}
