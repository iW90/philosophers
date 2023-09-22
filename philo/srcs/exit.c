/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:42:17 by inwagner          #+#    #+#             */
/*   Updated: 2023/09/21 22:42:26 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	james_kill_philos(t_philo **philos)
{
	int	i;

	i = -1;
	while (philos[++i])
		if (philos[i])
			free(philos[i]);
	free(philos);
}

int	end_dinner(char *msg, int error)
{
	t_butler	*james;

	if (msg)
		printf("%s\n", msg);
	james = call_butler();
	if (james->forks)
		james_kill_philos(james->forks);
	if(error)
		exit(error);
	return (0);
}
