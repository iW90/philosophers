/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:59:39 by inwagner          #+#    #+#             */
/*   Updated: 2023/09/23 15:06:40 by inwagner         ###   ########.fr       */
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
	LEFT_FORK = 4,
	RIGHT_FORK = 5
}	t_status;

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef struct s_philo
{
	int			index;
	pthread_t	*thread;
	t_status	status;
}				t_philo;

typedef struct s_butler
{
	int			total_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			total_meals;
	t_philo		**chairs;
}				t_butler;

t_butler	*call_butler(void);
int			atoui(char *str);
int			validate_invites(char **invites, int size);
void		instruct_the_butler(char **info, int len);
int			put_chairs(int total);
int			end_dinner(int error);


#endif