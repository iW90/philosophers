/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:11:24 by inwagner          #+#    #+#             */
/*   Updated: 2023/10/13 17:47:18 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	set_plates(int total, t_plate **table)
{
	t_plate			*plate;
	pthread_t		*philo;
	pthread_mutex_t	*hashi;

	plate = malloc(sizeof(t_plate) * total);
	philo = malloc(sizeof(pthread_t) * total);
	hashi = malloc(sizeof(pthread_mutex_t) * total);
	if (!plate || !philo || !hashi)
		return (finish_dinner(2, 0, 0));
	while (--total >= 0)
	{
		plate[total] = (t_plate){0};
		plate[total].philo = &philo[total];
		plate[total].hashi = &hashi[total];
		table[total] = &plate[total];
	}
	return (0);
}

int	set_table(int total)
{
	pthread_mutex_init(&call_butler()->printer, NULL);
	call_butler()->table = malloc(sizeof(t_plate *) * total);
	if (!call_butler()->table)
		return (finish_dinner(2, 0, 0));
	return (set_plates(total, call_butler()->table));
}

static void	set_hashis(t_plate **table, int total)
{
	table[0]->hashis[0] = 0;
	table[0]->hashis[1] = total - 1;
	while (--total > 0)
	{
		if (call_butler()->total_philos % 2 != 0 && \
			total % 2 != 0)
		{
			table[total]->hashis[0] = 0;
			table[total]->hashis[1] = -1;
		}
		else
		{
			table[total]->hashis[0] = -1;
			table[total]->hashis[1] = 0;
		}
	}
}

static int	get_hashis(t_plate **table, int total)
{
	set_hashis(table, total);
	while (--total >= 0)
		if (pthread_mutex_init(table[total]->hashi, NULL))
			return (call_butler()->total_philos - total - 1);
	return (0);
}

int	accommodate_guests(t_plate **table, int total)
{
	int	temp;

	temp = get_hashis(table, total);
	if (temp)
		return (finish_dinner(1, temp, 0));
	while (--total >= 0)
	{
		table[total]->id = total;
		table[total]->last_meal = get_time_in_usec();
		temp = pthread_create(table[total]->philo, NULL, \
			start_dinner, table[total]);
		if (temp)
			return (finish_dinner(5, call_butler()->total_philos, \
					call_butler()->total_philos - total - 1));
		if (total % 2 == 1)
			usleep(1000);
	}
	return (0);
}
