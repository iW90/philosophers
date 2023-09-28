/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:09:20 by inwagner          #+#    #+#             */
/*   Updated: 2023/09/27 21:04:23 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philosopher(void *arg)
{
	(void)arg;
	printf("HEEEEEEEEEEEEEEEEELP!\n");
	return (NULL);
}

int	accommodate_guests(t_plate **table, int total)
{
	while (--total >= 0)
	{
		table[total]->id = total;
		printf("Total: %i!\n", total);
		if (pthread_mutex_init(table[total]->hashi, NULL))
			return (end_dinner(1));
		if (pthread_create(table[total]->philo, NULL, philosopher, &table[total]->id))
			return (end_dinner(5));
		pthread_join(*table[total]->philo, NULL);
	}
	return (0);
}
