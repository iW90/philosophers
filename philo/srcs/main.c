/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:59:17 by inwagner          #+#    #+#             */
/*   Updated: 2023/09/21 21:59:08 by inwagner         ###   ########.fr       */
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
		end_dinner("The number of arguments should be four or five", -1);
	validate_invites(++av, --ac);
	instruct_the_butler(av, ac);
	put_chairs(--av, call_butler()->total_philos);

	return(end_dinner("The dinner was delicious!", 0));
}
