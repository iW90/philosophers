/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:11:24 by inwagner          #+#    #+#             */
/*   Updated: 2023/10/21 13:22:10 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_table(t_butler *james)
{
	james->philo = malloc(sizeof(t_philo));
	if (!james->philo)
		finish_dinner(2, FALSE);
	*james->philo = (t_philo){0};
	james->pids = malloc(sizeof(pid_t) * james->total_philos);
	if (!james->pids)
		finish_dinner(5, FALSE);
	james->hashis = sem_open("/hashis", O_CREAT, S_IRWXU, james->total_philos);
	if (james->hashis == SEM_FAILED)
		finish_dinner(1, TRUE);
	james->printer = sem_open("/printer", O_CREAT, S_IRWXU, 1);
	if (james->printer == SEM_FAILED)
		finish_dinner(6, TRUE);
	james->stop_father = sem_open("/stop_father", O_CREAT, S_IRWXU, james->total_philos);
	if (james->stop_father == SEM_FAILED)
		finish_dinner(6, TRUE);
	james->philo->stop_child = sem_open("/stop_child", O_CREAT, S_IRWXU, james->total_philos);
	if (james->philo->stop_child == SEM_FAILED)
		finish_dinner(6, TRUE);
	return (0);
}
