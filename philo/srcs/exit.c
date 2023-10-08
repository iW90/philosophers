/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:42:17 by inwagner          #+#    #+#             */
/*   Updated: 2023/10/08 12:01:35 by inwagner         ###   ########.fr       */
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
	if (!error)
		printf("Thanks for the dinner!\n");
}

int	end_dinner(int error)
{
	t_butler	*james;

	dinner_problems(error);
	james = call_butler();
	if (james->table)
	{
		if (james->table[0])
		{
			if (james->table[0]->philo)
			{
				pthread_join(*james->table[0]->philo, NULL);
				free(james->table[0]->philo);
			}
			if (james->table[0]->hashi)
			{
				pthread_mutex_destroy(james->table[0]->hashi);
				free(james->table[0]->hashi);
			}
			free(james->table[0]);
		}
		free(james->table);
	}
	if (&james->printer)
		pthread_mutex_destroy(&james->printer);
	return (error);
}
