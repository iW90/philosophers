/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_think.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:42:16 by inwagner          #+#    #+#             */
/*   Updated: 2023/10/11 22:22:37 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	hold_hashis(t_plate *philo, int left, int right)
{
	if (!philo->end_dinner && !philo->holding_hashis)
	{
		pthread_mutex_lock(&philo->hashi[left]);
		print_status(philo, LEFT_HASHI);
		philo->holding_hashis++;
	}
	if (!philo->end_dinner && philo->holding_hashis == 1)
	{
		pthread_mutex_lock(&philo->hashi[right]);
		print_status(philo, RIGHT_HASHI);
		philo->holding_hashis++;
	}
	return (0);
}

int	philo_thinking(t_plate *philo)
{
	if (philo->end_dinner)
		return (0);
	print_status(philo, THINKING);
	return(hold_hashis(philo, philo->hashis[0], philo->hashis[1]));
}
