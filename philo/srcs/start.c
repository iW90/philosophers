/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:09:20 by inwagner          #+#    #+#             */
/*   Updated: 2023/09/23 19:36:05 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philosopher(void *arg)
{
	(void)arg;
	printf("Calaio\n");
	return (NULL);
}

int	accommodate_guests(t_plate **table, int total)
{
	while (--total)
	{
		table[total]->id = total;
		printf("Teste1: %i\n", table[total]->id);
		printf("Teste2: %p\n", table[total]->philo);
		if (pthread_create(table[total]->philo, NULL, philosopher, &table[total]->id))
			return (end_dinner(5));
	}
	return (0);
}
