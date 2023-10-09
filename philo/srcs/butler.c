/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:18:51 by inwagner          #+#    #+#             */
/*   Updated: 2023/10/08 21:33:14 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	stop_simulation(t_plate *philo, t_plate **table, int total)
{
	print_status(philo, DIED);
	while (--total >= 0)
		table[total]->end_dinner = TRUE;
	return (1);
}

void	*stalk_table(void *arg)
{
	t_plate	**table;
	int		end_dinner;
	int		i;
	int		total;

	table = (t_plate **)arg;
	end_dinner = 0;
	total = call_butler()->total_philos;
	while (!end_dinner)
	{
		i = -1;
		while (++i < total)
		{
			if (table[i]->end_dinner)
			{
				end_dinner = stop_simulation(table[i], table, total);
				break ;
			}
		}
	}
	return (NULL);
}

int	watch_table(void)
{
	if (pthread_create(call_butler()->watcher, NULL, \
	stalk_table, call_butler()->table))
		return (end_dinner(5));
	return (0);
}
