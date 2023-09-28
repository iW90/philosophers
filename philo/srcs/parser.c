/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:11:24 by inwagner          #+#    #+#             */
/*   Updated: 2023/09/27 21:40:33 by inwagner         ###   ########.fr       */
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
	int				i;

	table = malloc(sizeof(t_plate *) * total);
	plate = malloc(sizeof(t_plate) * total);
	philo = malloc(sizeof(pthread_t) * total);
	hashi = malloc(sizeof(pthread_mutex_t) * total);
	hashis = malloc(sizeof(unsigned int) * total * 2);
	if (!table || !plate || !philo || !hashi || !hashis)
		return (end_dinner(2));
	call_butler()->table = table;
	i = -1;
	while (++i < total)
	{
		hashis[i] = 0;
		hashis[i * 2] = 0;
		plate[i] = (t_plate){0};
		plate[i].philo = &philo[i];
		plate[i].hashi = &hashi[i];
		plate[i].hashis = &hashis[i * 2];
		table[i] = &plate[i];
	}
	return (0);
}
