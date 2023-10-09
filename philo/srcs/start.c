/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:09:20 by inwagner          #+#    #+#             */
/*   Updated: 2023/10/08 21:29:02 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	what_philo_is_doing(t_plate	*philo)
{
	philo_thinking(philo);
	philo_eating(philo);
	philo_sleeping(philo);
	return (0);
}

void	*start_dinner(void *arg)
{
	t_plate		*philo;
	t_butler	*james;

	philo = (t_plate *)arg;
	james = call_butler();
	while (!philo->end_dinner && james->total_must_eat != philo->total_ate)
		what_philo_is_doing(philo);
	return (NULL);
}

static void	set_hashis(t_plate **table, int total)
{
	table[0]->hashis[0] = 0;
	table[0]->hashis[1] = total - 1;
	while (--total > 0)
	{
		table[total]->hashis[0] = -1;
		table[total]->hashis[1] = 0;
	}
}

int	accommodate_guests(t_plate **table, int total)
{
	pthread_mutex_init(&call_butler()->printer, NULL);
	set_hashis(table, total);
	while (--total >= 0)
	{
		table[total]->id = total;
		if (pthread_mutex_init(table[total]->hashi, NULL))
			return (end_dinner(1));
		table[total]->last_meal = get_time_in_usec();
		if (pthread_create(table[total]->philo, NULL, \
			start_dinner, table[total]))
			return (end_dinner(5));
	}
	if(watch_table())
		return (5);
	return (0);
}