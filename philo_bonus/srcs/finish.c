/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:42:17 by inwagner          #+#    #+#             */
/*   Updated: 2023/10/13 23:06:57 by inwagner         ###   ########.fr       */
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

int	finish_dinner(int error)
{
	t_butler	*james;

	dinner_problems(error);
	james = call_butler();
	if (james->table)
	{
		if (james->table[0])
		{
			//fechar forks
			sem_unlink("/hashis");
			free(james->table[0]);
		}
		free(james->table);
	}
	sem_unlink("/printer");
	return (error);
}

void	clear_sem(void)
{
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/end");
	sem_unlink("/philo_done");
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
