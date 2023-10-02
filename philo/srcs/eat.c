/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:30:40 by inwagner          #+#    #+#             */
/*   Updated: 2023/10/01 21:24:56 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eating(t_plate *philo)
{
	philo->status = EATING;
	philo->last_meal = print_status(philo);
	usleep(call_butler()->time_to_eat);
}
