/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:11:24 by inwagner          #+#    #+#             */
/*   Updated: 2023/10/10 22:51:32 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_plates(int total, t_plate **table)
{
	t_plate			*plate;
	pthread_t		*philo;
	pthread_mutex_t	*hashi;

	plate = malloc(sizeof(t_plate) * total);
	philo = malloc(sizeof(pthread_t) * total);
	hashi = malloc(sizeof(pthread_mutex_t) * total);
	if (!plate || !philo || !hashi)
		return (end_dinner(2));
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
	call_butler()->table = malloc(sizeof(t_plate *) * total);
	if (!call_butler()->table)
		return (end_dinner(2));
	return (set_plates(total, call_butler()->table));
}
