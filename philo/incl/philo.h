/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:59:39 by inwagner          #+#    #+#             */
/*   Updated: 2023/09/19 22:32:45 by inwagner         ###   ########.fr       */
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

#ifndef INT_MAX
# define INT_MAX 2147483647
#endif

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

int		ft_isblank(int c);
int		ft_isdigit(int c);
int		ft_unsigned_atoi(char *str);

#endif