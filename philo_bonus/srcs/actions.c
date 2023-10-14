/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:42:16 by inwagner          #+#    #+#             */
/*   Updated: 2023/10/13 23:06:55 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	hold_hashis(t_philo *philo, int left, int right)
{
	if (!call_butler()->stop && !philo->holding_hashis)
	{
		sem_wait(call_butler()->hashis);
		print_status(philo, "has taken a fork\n");
		philo->holding_hashis++;
	}
	if (!call_butler()->stop && philo->holding_hashis == 1 && \
		call_butler()->total_philos > 1)
	{
		sem_wait(call_butler()->hashis);
		print_status(philo, "has taken a fork\n");
		philo->holding_hashis++;
	}
	return (0);
}

static int	drop_hashis(t_philo *philo, int left, int right)
{
	if (philo->holding_hashis == 2)
	{
		sem_post(call_butler()->hashis);
		philo->holding_hashis--;
	}
	if (philo->holding_hashis == 1 && \
		call_butler()->total_philos > 1)
	{
		sem_post(call_butler()->hashis);
		philo->holding_hashis--;
	}
	return (0);
}

int	philo_thinking(t_philo *philo)
{
	if (call_butler()->stop)
		return (0);
	print_status(philo, "is thinking\n");
	return (hold_hashis(philo, philo->hashis[0], philo->hashis[1]));
}

int	philo_eating(t_philo *philo)
{
	if (call_butler()->stop)
		return (drop_hashis(philo, philo->hashis[0], philo->hashis[1]));
	if (philo->holding_hashis == 2)
	{
		philo->last_meal = print_status(philo, "is eating\n");
		usleep(call_butler()->time_to_eat);
		if (++philo->total_ate == call_butler()->total_must_eat)
			call_butler()->stop = TRUE;
		return (drop_hashis(philo, philo->hashis[0], philo->hashis[1]));
	}
	drop_hashis(philo, philo->hashis[0], philo->hashis[1]);
	usleep(call_butler()->time_to_die + 1000);
	return (1);
}

int	philo_sleeping(t_philo *philo)
{
	if (call_butler()->stop)
		return (0);
	print_status(philo, "is sleeping\n");
	usleep(call_butler()->time_to_sleep);
	return (0);
}
