/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:11:24 by inwagner          #+#    #+#             */
/*   Updated: 2023/09/21 22:43:07 by inwagner         ###   ########.fr       */
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

static void	clean_forks(t_philo **fork, int total)
{
	int	i;

	i = -1;
	while (++i < total)
		fork[i] = NULL;
}

void	put_forks(int total)
{
	t_philo		**forks;
	int			i;

	forks = NULL;
	forks = malloc(sizeof(t_philo) * total + 1);
	if (!forks)
		end_dinner("We don't have enough forks.", 2);
	call_butler()->forks = forks;
	clean_forks(forks, total);
	i = -1;
	while (++i < total)
	{
		forks[i] = malloc(sizeof(t_philo));
		if (!forks[i])
			end_dinner("We don't have enough forks.", 2);
		forks[i] = (t_philo *){0};
	}
}
