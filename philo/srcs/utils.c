/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:08:50 by inwagner          #+#    #+#             */
/*   Updated: 2023/09/19 21:45:06 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isblank(int c)
{
	return (c == ' ' || c == '\t');
}

int	ft_isdigit(int c)
{
	return ((unsigned)c - '0' < 10);
}

int	ft_unsigned_atoi(char *str)
{
	unsigned int	number;
	int				i;

	i = 0;
	number = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	if (number > INT_MAX)
		return (-1);
	return ((int)number);
}
