/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:22:24 by inwagner          #+#    #+#             */
/*   Updated: 2023/10/13 23:41:56 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	child_actions(t_butler james, int id, time_t last_meal)
{
	james->philo->id = id;
	//pthread_create(&james->thread[0], NULL, ?, james->philo);
	if (id % 2)
		usleep(50);
	
	return (0);
}

void	child_actions(t_butler *james, int id, time_t last_meal)
{
	james->philo->id = id;
	james->philo->last_meal = last_meal;
	if (id % 2)
		usleep(50);
	pthread_create(&james->thread[0], NULL, have_dinner, james->philo);
	pthread_create(&james->thread[1], NULL, hold_philo, james);
	attend_dinner(james);
	while (!james->philo->stop)
	{
		usleep(1000);
		loop_simulation(james);
	}
	pthread_join(james->thread[0], NULL);
	pthread_join(james->thread[1], NULL);
	end_dinner(0);
}
