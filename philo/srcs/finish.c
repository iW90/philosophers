/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:42:17 by inwagner          #+#    #+#             */
/*   Updated: 2023/10/15 20:52:02 by inwagner         ###   ########.fr       */
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

static void	kill_philos(t_plate **table, int total)
{
	if (table[0]->philo)
	{
		while (--total >= 0)
			pthread_join(*table[total]->philo, NULL);
		free(table[0]->philo);
	}
}

static void	clean_hashis(t_plate **table, int total)
{
	if (table[0]->hashi)
	{
		while (--total >= 0)
			pthread_mutex_destroy(table[total]->hashi);
		free(table[0]->hashi);
	}
}

int	finish_dinner(int error, int mtx, int thrd)
{
	t_butler	*james;

	dinner_problems(error);
	james = call_butler();
	if (james->table)
	{
		if (james->table[0])
		{
			kill_philos(&james->table[0], mtx);
			clean_hashis(&james->table[0], thrd);
			free(james->table[0]);
		}
		free(james->table);
	}
	pthread_mutex_destroy(&james->printer);
	return (error);
}

void	stalk_table(t_butler *james, t_plate **table, int total)
{
	int		i;

	while (!james->stop)
	{
		i = -1;
		while (++i < total)
		{
			if (james->total_philos == james->all_ate)
			{
				james->stop = TRUE;
				break ;
			}
			else if (is_dead(table[i]) || james->stop)
			{
				print_status(table[i], "died\n");
				james->stop = TRUE;
				break ;
			}
		}
		usleep(1000);
	}
}
