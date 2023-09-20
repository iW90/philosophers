/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:59:17 by inwagner          #+#    #+#             */
/*   Updated: 2023/09/19 22:43:05 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_x	*get_x(void)
{
	static t_x	x;

	return (&x);
}

// (str)		program_name
// (int)		number_of_philosophers
// (ms)			time_to_die
// (ms)			time_to_eat
// (ms)			time_to_sleep
// (str int)	[number_of_times_each_philosopher_must_eat] -----opcional
int	main(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (1);
	if (!is_input_valid(++av, --ac))
		return (1);
	
	return (0);
}
