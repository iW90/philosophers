/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:11:24 by inwagner          #+#    #+#             */
/*   Updated: 2023/10/13 23:42:30 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_table(int total, t_butler james)
{
	james->philo = malloc(sizeof(t_philo));
	if (!james->philo)
		return (finish_dinner(2));
	james->philo = (t_philo){0};
	james->pids = malloc(sizeof(pid_t) * james->total_philos);
	if (!james->pids)
		return (finish_dinner(5));
	james->hashis = sem_open("/hashis", O_CREAT, S_IRWXU, james->total_philos);
	if (james->hashis == SEM_FAILED)
		return (finish_dinner(1));
	james->printer = sem_open("/printer", O_CREAT, S_IRWXU, 1);
	if (james->printer == SEM_FAILED)
		return (finish_dinner(6));
	james->stop = sem_open("/stop_father", O_CREAT, S_IRWXU, 0);
	if (james->stop_father == SEM_FAILED)
		return (finish_dinner(6));
	james->stop = sem_open("/stop_child", O_CREAT, S_IRWXU, 0);
	if (james->philo->stop_child == SEM_FAILED)
		return (finish_dinner(6));
	return (0);
}
