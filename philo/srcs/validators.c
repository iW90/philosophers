/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:31:49 by inwagner          #+#    #+#             */
/*   Updated: 2023/09/23 18:23:27 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c)
{
	return ((unsigned)c - '0' < 10);
}

int	ratatoui(char *str)
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

static t_bool	has_fake_invite(char *invite)
{
	int	i;

	i = -1;
	while (invite[++i])
		if (!ft_isdigit(invite[i]))
			return (FALSE);
	return (TRUE);
}

int	validate_invites(char **invites, int size)
{
	int	i;
	int	number;

	i = -1;
	while (++i < size)
	{
		if (!has_fake_invite(invites[i]))
			return (end_dinner(2));
		number = ratatoui(invites[i]);
		if (i == 1 && (number <= 0 || number > MAX_PHILOS))
			return (end_dinner(3));
		if (i >= 2 && number < 0)
			return (end_dinner(4));
	}
	return (0);
}
