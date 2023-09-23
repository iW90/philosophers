/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:42:17 by inwagner          #+#    #+#             */
/*   Updated: 2023/09/23 15:07:46 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	dinner_problems(int	error)
{
	if (error == -1)
		printf("The number of arguments should be four or five\n");
	if (error == 1)
		printf("We don't have enough chairs.\n");
	if (error == 2)
		printf("Some invitations are fake. Only numeric digits are accepted\n");
	if (error == 3)
		printf("At least one philosopher needs to have accepted the invitation\n");
	if (error == 4)
		printf("There are only two hundred chairs, invite fewer philosophers\n");
	if (error == 5)
		printf("Take as much time as you need, as long as it's greater than zero\n");


	if (!error)
		printf("The dinner was delicious!\n");
}

static void	james_kill_philos(t_philo **philos)
{
	int	i;

	i = -1;
	while (philos[++i])
		if (philos[i])
			free(philos[i]);
	free(philos);
}

int	end_dinner(int error)
{
	t_butler	*james;

	dinner_problems(error);
	james = call_butler();
	if (james->chairs)
		james_kill_philos(james->chairs);
	return (0);
}
