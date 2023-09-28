/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:59:39 by inwagner          #+#    #+#             */
/*   Updated: 2023/09/27 22:21:28 by inwagner         ###   ########.fr       */
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

typedef enum e_status
{
	DIED = 0,
	EATING = 1,
	SLEEPING = 2,
	THINKING = 3,
	LEFT_HASHI = 4,
	RIGHT_HASHI = 5
}	t_status;

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
	unsigned int	*hashis;
	unsigned int	total_ate;
	time_t			last_meal;
	t_status		status;
}					t_plate;

typedef struct s_butler
{
	t_plate			**table;
	unsigned int	total_philos;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	unsigned int	total_must_eat;
}					t_butler;

t_butler	*call_butler(void);
int			ratatoui(char *str);
int			validate_invites(char **invites, int size);
void		instruct_the_butler(char **info, int len);
int			set_table(int total);
int			accommodate_guests(t_plate **table, int total);
time_t		get_time_in_usec(void);
int			end_dinner(int error);

void		*philosopher(void *arg);

#endif