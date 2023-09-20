/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:31:49 by inwagner          #+#    #+#             */
/*   Updated: 2023/09/19 22:12:53 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	is_str_valid(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(av[i]) || !ft_isblank(av[i]))
			return (FALSE);
	return (TRUE);
}

t_bool	is_input_valid(char **data, int	size)
{
	int	i;
	int	number;

	i = -1;
	while (++i < size)
		if (!is_str_valid(data[i]))
			return (FALSE);
	i = -1;
	while (++i < size - 1)
	{
		number = ft_unsigned_atoi(data[i]);
		if ((i == 1 && (number <= 0 || number > MAX_PHILOS)) || \
			(i >= 2 && number < 0))
			return (FALSE);
	}
	return (TRUE)
}
