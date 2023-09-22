/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:11:24 by inwagner          #+#    #+#             */
/*   Updated: 2023/09/21 22:17:34 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	instruct_the_butler(char **info, int len)
{
	t_butler	*james;

	james = call_butler();
	james->total_philos = atoui(info[0]);
	james->time_to_die = atoui(info[1]);
	james->time_to_eat = atoui(info[2]);
	james->time_to_sleep = atoui(info[3]);
	if (len == 5)
		james->total_meals = atoui(info[4]);
}

static void	clean_chairs(t_philo **chair, int total)
{
	int	i;

	i = -1;
	while (++i < total)
		chair[i] = NULL;
}

void	put_chairs(int total)
{
	t_philo		**chairs;
	int			i;

	chairs = NULL;
	chairs = malloc(sizeof(t_philo) * total + 1);
	if (!chairs)
		end_dinner("We don't have enough chairs.", 2);
	call_butler()->philos = chairs;
	clean_chairs(chairs, total);
	i = -1;
	while (++i < total)
	{
		chairs[i] = malloc(sizeof(t_philo));
		if (!chairs[i])
			end_dinner("We don't have enough chairs.", 2);
		chairs[i] = (t_philo *){0};
	}
}
