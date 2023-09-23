/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:11:24 by inwagner          #+#    #+#             */
/*   Updated: 2023/09/23 20:36:48 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_table(int total)
{
	t_plate		**table;
	t_plate		*plate;
	pthread_t	*philo;
	int			i;

	table = malloc(sizeof(t_plate *) * total);
	plate = malloc(sizeof(t_plate) * total);
	philo = malloc(sizeof(pthread_t) * total);
	if (!table || !plate || !philo)
		return (end_dinner(2));
	call_butler()->table = table;
	i = -1;
	while (++i < total)
	{
		philo[i] = (pthread_t){0};
		plate[i].philo = &philo[i];
		table[i] = &plate[i];
	}
	return (0);
}
