/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_sleep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:43:06 by inwagner          #+#    #+#             */
/*   Updated: 2023/10/11 21:20:05 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_sleeping(t_plate *philo)
{
	if (philo->end_dinner)
		return (0);
	print_status(philo, SLEEPING);
	usleep(call_butler()->time_to_sleep);
	return (0);
}
