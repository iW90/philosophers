/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:11:24 by inwagner          #+#    #+#             */
/*   Updated: 2023/10/01 20:56:05 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_table(int total)
{
	t_plate			**table;
	t_plate			*plate;
	pthread_t		*philo;
	pthread_mutex_t	*hashi;
	unsigned int	*hashis;

	table = malloc(sizeof(t_plate *) * total);
	plate = malloc(sizeof(t_plate) * total);
	philo = malloc(sizeof(pthread_t) * total);
	hashi = malloc(sizeof(pthread_mutex_t) * total);
	hashis = malloc(sizeof(unsigned int) * total * 2);
	if (!table || !plate || !philo || !hashi || !hashis)
		return (end_dinner(2));
	call_butler()->table = table;
	while (--total >= 0)
	{
		hashis[total] = 0;
		hashis[total * 2] = 0;
		plate[total] = (t_plate){0};
		plate[total].philo = &philo[total];
		plate[total].hashi = &hashi[total];
		plate[total].hashis = &hashis[total * 2];
		table[total] = &plate[total];
	}
	return (0);
}
