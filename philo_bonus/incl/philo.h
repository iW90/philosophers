/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:59:39 by inwagner          #+#    #+#             */
/*   Updated: 2023/10/14 11:25:41 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# define MAX_PHILOS 200

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef struct s_philo
{
	unsigned int	id;
	unsigned int	holding_hashis;
	unsigned int	total_ate;
	_Atomic time_t	last_meal;
	sem_t			*stop_child;
}					t_philo;

typedef struct s_butler
{
	_Atomic t_bool	stop;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				total_philos;
	unsigned int	total_must_eat;
	pid_t			*pids;
	t_philo			*philo;
	sem_t			*stop_father;
	sem_t			*hashis;
	sem_t			*printer;
	pthread_t		thread[2];
}					t_butler;

t_butler	*call_butler(void);
void		stalk_table(t_philo *philo);
void		finish_dinner(int error, int finish);

int			philo_thinking(t_philo *philo);
int			philo_eating(t_philo *philo);
int			philo_sleeping(t_philo *philo);

int			accommodate_guests(t_butler *james, int total);
int			set_table(t_butler *james);
int			validate_invites(char **invites, int size);
void		child_actions(t_butler *james, int id, time_t last_meal);

time_t		print_status(t_philo *philo, char *str);
time_t		get_time_in_usec(void);
int			is_dead(t_philo *philo);
int			ratatoui(char *str);

#endif