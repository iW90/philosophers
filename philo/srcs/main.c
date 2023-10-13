/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:59:17 by inwagner          #+#    #+#             */
/*   Updated: 2023/10/13 11:18:43 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_butler	*call_butler(void)
{
	static t_butler	james;

	return (&james);
}

static void	inform_butler(char **info, int len)
{
	t_butler	*james;

	james = call_butler();
	james->total_philos = ratatoui(info[0]);
	james->time_to_die = ratatoui(info[1]) * 1000;
	james->time_to_eat = ratatoui(info[2]) * 1000;
	james->time_to_sleep = ratatoui(info[3]) * 1000;
	if (len == 5)
		james->total_must_eat = ratatoui(info[4]);
	else
		james->total_must_eat = 0;
}

static int	what_philo_is_doing(t_plate	*philo)
{
	philo_thinking(philo);
	philo_eating(philo);
	philo_sleeping(philo);
	return (0);
}

void	*start_dinner(void *arg)
{
	t_plate		*philo;

	philo = (t_plate *)arg;
	while (!philo->end_dinner)
		what_philo_is_doing(philo);
	return (NULL);
}

int	main(int ac, char **av)
{
	unsigned int	total;

	if (ac < 5 || ac > 6)
		return (finish_dinner(-1, 0, 0));
	if (validate_invites(++av, --ac))
		return (-1);
	inform_butler(av, ac);
	total = call_butler()->total_philos;
	if (set_table(total))
		return (2);
	if (accommodate_guests(call_butler()->table, total))
		return (3);
	stalk_table(call_butler()->table, total);
	return (finish_dinner(0, total, total));
}
