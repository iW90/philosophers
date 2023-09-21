/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:31:49 by inwagner          #+#    #+#             */
/*   Updated: 2023/09/21 17:51:45 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c)
{
	return ((unsigned)c - '0' < 10);
}

static int	ft_unsigned_atoi(char *str)
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

static t_bool	is_str_digit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(av[i]))
			return (FALSE);
	return (TRUE);
}

t_bool	is_input_valid(char **data, int	size)
{
	int	i;
	int	number;

	i = -1;
	while (++i < size)
	{
		if (!is_str_digit(data[i]))
			return (FALSE);
		number = ft_unsigned_atoi(data[i]);
		if ((i == 1 && (number <= 0 || number > MAX_PHILOS)) || \
			(i >= 2 && number < 0))
			return (FALSE);
	}
	return (TRUE)
}
