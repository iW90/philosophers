/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:59:39 by inwagner          #+#    #+#             */
/*   Updated: 2023/10/15 20:54:07 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdbool.h>

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# define MAX_PHILOS 200

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef struct s_plate
{
	unsigned int	id;
	pthread_mutex_t	*hashi;
	pthread_t		*philo;
	unsigned int	hashis[2];
	unsigned int	holding_hashis;
	unsigned int	total_ate;
	_Atomic time_t	last_meal;
}					t_plate;

typedef struct s_butler
{
	t_plate					**table;
	unsigned int			total_philos;
	time_t					time_to_die;
	time_t					time_to_eat;
	time_t					time_to_sleep;
	_Atomic int				stop;
	_Atomic unsigned int	total_must_eat;
	_Atomic unsigned int	all_ate;
	pthread_mutex_t		printer;
}					t_butler;

t_butler	*call_butler(void);
void		*start_dinner(void *arg);
void		stalk_table(t_butler *james, t_plate **table, int total);
int			finish_dinner(int error, int mtx, int thrd);

int			philo_thinking(t_plate *philo);
int			philo_eating(t_plate *philo);
int			philo_sleeping(t_plate *philo);

int			accommodate_guests(t_plate **table, int total);
int			set_table(int total);
int			validate_invites(char **invites, int size);

time_t		print_status(t_plate *philo, char *str);
time_t		get_time_in_usec(void);
int			is_dead(t_plate *philo);
int			ratatoui(char *str);

#endif