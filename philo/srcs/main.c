/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:59:17 by inwagner          #+#    #+#             */
/*   Updated: 2023/09/23 15:09:12 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_butler	*call_butler(void)
{
	static t_butler	james;

	return (&james);
}

int	main(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (end_dinner(-1));
	if (!validate_invites(++av, --ac))
		return (-1);
	instruct_the_butler(av, ac);
	if (!put_chairs(call_butler()->total_philos))
		return (2);

	return(end_dinner(0));
}
