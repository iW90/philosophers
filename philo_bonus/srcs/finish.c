/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:42:17 by inwagner          #+#    #+#             */
/*   Updated: 2023/10/21 13:19:16 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	dinner_problems(int error)
{
	if (error == -1)
		printf("The number of arguments should be four or five.\n");
	if (error == 1)
		printf("We don't have enough space.\n");
	if (error == 2)
		printf("Some invitations are fake. Only numeric digits are accepted.\n");
	if (error == 3)
		printf("Please, invite between 1 and 200 guests.\n");
	if (error == 4)
		printf("Take as much time as you need, but not too much.\n");
	if (error == 5)
		printf("Guest refuse invite.\n");
	if (error == 6)
		printf("Butler is not around.\n");
}

static void	finish_father(t_butler *james, int finish)
{
	if (james->hashis)
	{
		sem_close(james->hashis);
		if (finish)
			sem_unlink("/hashis");
	}
	if (james->printer)
	{
		sem_close(james->printer);
		if (finish)
			sem_unlink("/printer");
	}
	if (james->stop_father)
	{
		sem_close(james->stop_father);
		if (finish)
			sem_unlink("/stop_father");
	}
}

void	finish_dinner(int error, int finish)
{
	t_butler	*james;

	dinner_problems(error);
	james = call_butler();
	finish_father(james, finish);
	if (james->philo)
	{
		if (james->philo->stop_child)
		{
			sem_close(james->philo->stop_child);
			if (finish)
				sem_unlink("/stop_child");
		}
		free(james->philo);
	}
	if (james->pids)
		free(james->pids);
	exit (error);
}

static void	over_and_out(t_butler *james)
{
	sem_post(james->philo->stop_child);
	while (TRUE)
	{
		if (james->stop)
			break ;
	}
	while (james->philo->holding_hashis)
	{
		sem_post(james->hashis);
		james->philo->holding_hashis--;
	}
	sem_post(james->printer);
	pthread_join(james->thread[0], NULL);
	pthread_join(james->thread[1], NULL);
	finish_dinner(0, FALSE);
}

void	stalk_table(t_philo *philo)
{
	while (!call_butler()->stop)
	{
		if (call_butler()->total_must_eat && \
			philo->total_ate == call_butler()->total_must_eat)
		{
			sem_wait(call_butler()->printer);
			over_and_out(call_butler());
		}
		else if (is_dead(philo))
		{
			sem_wait(call_butler()->printer);
			printf("%li %i is dead\n", get_time_in_usec() / 1000, philo->id + 1);
			over_and_out(call_butler());
		}
		usleep(1000);
	}
}
