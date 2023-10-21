/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:22:24 by inwagner          #+#    #+#             */
/*   Updated: 2023/10/21 13:29:09 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	what_philo_is_doing(t_philo	*philo)
{
	if (!call_butler()->stop)
	{
		philo_thinking(philo);
		philo_eating(philo);
	}
	if (!call_butler()->stop)
		philo_sleeping(philo);
	return (0);
}

static void	*start_dinner(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	while (!call_butler()->stop)
		what_philo_is_doing(philo);
	return (NULL);
}

static void	*hold_philo(void *arg)
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
	sem_wait(james->stop_father);
	sem_wait(james->philo->stop_child);
	if (id % 2)
		usleep(50);
	pthread_create(&james->thread[0], NULL, start_dinner, james->philo);
	pthread_create(&james->thread[1], NULL, hold_philo, james);
	stalk_table(james->philo);
	pthread_join(james->thread[0], NULL);
	pthread_join(james->thread[1], NULL);
	finish_dinner(0, FALSE);
}
