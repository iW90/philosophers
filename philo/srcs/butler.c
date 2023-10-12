/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:18:51 by inwagner          #+#    #+#             */
/*   Updated: 2023/10/11 21:13:04 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	stop_simulation(t_plate *philo, t_plate **table, int total)
{
	print_status(philo, DIED);
	call_butler()->stop = TRUE;
	while (--total >= 0)
		table[total]->end_dinner = TRUE;
	return (TRUE);
}

void	stalk_table(t_plate **table, int total)
{
	int		stop;
	int		i;

	stop = 0;
	while (!stop)
	{
		i = -1;
		while (++i < total)
		{
			if (table[i]->end_dinner || is_dead(table[i]))
			{
				stop = stop_simulation(table[i], table, total);
				break ;
			}
		}
		usleep(100 * 1000);
	}
}
