/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:31:49 by inwagner          #+#    #+#             */
/*   Updated: 2023/09/21 22:07:12 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c)
{
	return ((unsigned)c - '0' < 10);
}

int	atoui(char *str)
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

void	validate_invites(char **data, int size)
{
	int	i;
	int	number;

	i = -1;
	while (++i < size)
	{
		if (!has_fake_invite(data[i]))
			end_dinner(\
		"Some invitations are fake. Only numeric digits are accepted", 1);
		number = atoui(data[i]);
		if (i == 1 && number <= 0)
			end_dinner(\
		"At least one philosopher needs to have accepted the invitation", 1);
		if (i == 1 && number > MAX_PHILOS)
			end_dinner(\
		"There are only two hundred chairs, invite fewer philosophers", 1);
		if (i >= 2 && number < 0)
			end_dinner(\
		"Take as much time as you need, as long as it's greater than zero", 1);
	}
}
