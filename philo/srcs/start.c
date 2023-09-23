/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:09:20 by inwagner          #+#    #+#             */
/*   Updated: 2023/09/23 20:35:46 by inwagner         ###   ########.fr       */
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
	while (--total)
	{
		table[total]->id = total;
		if (pthread_create(table[total]->philo, NULL, philosopher, &table[total]->id))
			return (end_dinner(5));
	}
	return (0);
}
