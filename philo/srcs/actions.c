/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:42:16 by inwagner          #+#    #+#             */
/*   Updated: 2023/10/15 18:45:46 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	hold_hashis(t_plate *philo, int left, int right)
{
	if (!call_butler()->stop && !philo->holding_hashis)
	{
		pthread_mutex_lock(&philo->hashi[left]);
		print_status(philo, "has taken a fork\n");
		philo->holding_hashis++;
	}
	if (!call_butler()->stop && philo->holding_hashis == 1 && \
		call_butler()->total_philos > 1)
	{
		pthread_mutex_lock(&philo->hashi[right]);
		print_status(philo, "has taken a fork\n");
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
	if (call_butler()->stop)
		return (0);
	print_status(philo, "is thinking\n");
	return (hold_hashis(philo, philo->hashis[0], philo->hashis[1]));
}

int	philo_eating(t_plate *philo)
{
	if (call_butler()->stop)
		return (drop_hashis(philo, philo->hashis[0], philo->hashis[1]));
	if (philo->holding_hashis == 2)
	{
		philo->last_meal = print_status(philo, "is eating\n");
		usleep(call_butler()->time_to_eat);
		philo->total_ate++;
		return (drop_hashis(philo, philo->hashis[0], philo->hashis[1]));
	}
	drop_hashis(philo, philo->hashis[0], philo->hashis[1]);
	usleep(call_butler()->time_to_die + 1000);
	return (1);
}

int	philo_sleeping(t_plate *philo)
{
	if (call_butler()->stop)
		return (0);
	print_status(philo, "is sleeping\n");
	usleep(call_butler()->time_to_sleep);
	return (0);
}
