/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:22:24 by inwagner          #+#    #+#             */
/*   Updated: 2023/10/14 11:01:55 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*hold_philo(void *arg)
{
	t_butler	*james;

	james = (t_butler *)arg;
	sem_wait(james->stop_father);
	james->stop = TRUE;
	return (NULL);
}

void	child_actions(t_butler *james, int id, time_t last_meal)
{
	james->philo->id = id;
	james->philo->last_meal = last_meal;
	if (id % 2)
		usleep(50);
	pthread_create(&james->thread[0], NULL, start_dinner, james->philo);
	pthread_create(&james->thread[1], NULL, hold_philo, james);
	stalk_table(james);
	pthread_join(james->thread[0], NULL);
	pthread_join(james->thread[1], NULL);
	finish_dinner(0, FALSE);
}
