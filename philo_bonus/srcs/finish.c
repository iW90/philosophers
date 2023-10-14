/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:42:17 by inwagner          #+#    #+#             */
/*   Updated: 2023/10/14 09:47:05 by inwagner         ###   ########.fr       */
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

int	finish_dinner(int error, int finish)
{
	t_butler	*james;

	dinner_problems(error);
	james = call_butler();
	finish_father(james, finish);
	if (james->philo)
	{
		if (james->philo->stop_child)
		{
			sem_close(james->stop_child);
			if (finish)
				sem_unlink("/stop_child");
		}
		free(james->philo)
	}
	if (james->pids)
		free(james->pids);
	return (error);
}

void	clear_sem(void)
{
	sem_unlink("/hashis");
	sem_unlink("/printer");
	sem_unlink("/stop_father");
	sem_unlink("/stop_child");
}

void	stalk_table(t_philo **table, int total)
{
	int		i;

	while (!call_butler()->stop)
	{
		i = -1;
		while (++i < total)
		{
			if (is_dead(table[i]) || call_butler()->stop)
			{
				print_status(table[i], "is dead\n");
				call_butler()->stop = TRUE;
				break ;
			}
		}
		usleep(100 * 1000);
	}
}
