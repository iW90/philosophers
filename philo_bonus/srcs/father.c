/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   father.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 23:28:00 by inwagner          #+#    #+#             */
/*   Updated: 2023/10/14 10:02:23 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*wait_child(void *arg)
{
	int			i;
	t_butler	*james;

	i = -1;
	james = (t_butler *)arg;
	sem_wait(james->philo->stop_child);
	while (++i < james->total_philos)
		kill(james->pids[i], SIGSTOP);
	i = -1;
	while (++i < james->total_philos)
		sem_post(james->stop_father);
	i = -1;
	while (++i < james->total_philos)
		kill(james->pids[i], SIGCONT);
	return (NULL);
}

static int	wait_all(pid_t *pids, int total)
{
	int	i;
	int	status;

	i = -1;
	while (++i < total)
		if (pids[i] > 0)
			waitpid(pids[i], &status, 0);
	return (TRUE);
}

int	accommodate_guests(t_butler james, int total)
{
	int	proceed;

	proceed = FALSE;
	while (--total >= 0)
	{
		james->pids[i] = fork();
		if (james->pids[i] < 0)
			finish_dinner(5);
		else if (james->pids[i] == 0)
			child_actions(james, total, get_time_in_usec());
	}
	pthread_create(james->thread[0], NULL, wait_child, james);
	while (!proceed)
		proceed = wait_all(james->pids, james->total_philos);
	pthread_join(james->thread[0], NULL);
	return (0);
}
