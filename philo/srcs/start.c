/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:09:20 by inwagner          #+#    #+#             */
/*   Updated: 2023/10/08 12:03:14 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher(void *arg)
{
	t_plate	*philo;

	philo = (t_plate *)arg;
	print_status(philo);
	return (NULL);
}

int	accommodate_guests(t_plate **table, int total)
{
	pthread_mutex_init(&call_butler()->printer, NULL);
	while (--total >= 0)
	{
		table[total]->id = total;
		if (pthread_mutex_init(table[total]->hashi, NULL))
			return (end_dinner(1));
		if (pthread_create(table[total]->philo, NULL, \
			philosopher, table[total]))
			return (end_dinner(5));
	}
	return (0);
}
