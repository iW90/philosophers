/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:34:26 by inwagner          #+#    #+#             */
/*   Updated: 2023/10/01 21:27:50 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	print_status(int philo)
{
	time_t	time;

	time = get_time_in_usec();
	printf("[%li] Philo %i", time / 1000, philo->id);
	if (!philo->status)
		printf("Died.\n");
	if (philo->status == 1)
		printf("Eating.\n");
	if (philo->status == 2)
		printf("Sleeping.\n");
	if (philo->status == 3)
		printf("Thinking.\n");
	if (philo->status == 4)
		printf("Holding Left Hashi\n");
	if (philo->status == 5)
		printf("Holding Right Hashi\n");
	return (time);
}
