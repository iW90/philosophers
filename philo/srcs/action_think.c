/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_think.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:42:16 by inwagner          #+#    #+#             */
/*   Updated: 2023/10/08 21:27:07 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	hold_hashis(t_plate *philo, int left, int right)
{
	pthread_mutex_lock(&philo->hashi[left]);
	print_status(philo, LEFT_HASHI);
	pthread_mutex_lock(&philo->hashi[right]);
	print_status(philo, RIGHT_HASHI);
	return (0);
}

int	philo_thinking(t_plate *philo)
{
	print_status(philo, THINKING);
	return(hold_hashis(philo, philo->hashis[0], philo->hashis[1]));
}
