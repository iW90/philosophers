/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:31:49 by inwagner          #+#    #+#             */
/*   Updated: 2023/10/14 09:56:13 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c)
{
	return ((unsigned)c - '0' < 10);
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
			finish_dinner(2, FALSE);
		number = ratatoui(invites[i]);
		if (i == 0 && (number <= 0 || number > MAX_PHILOS))
			finish_dinner(3, FALSE);
		if (i >= 1 && number < 0)
			finish_dinner(4, FALSE);
	}
	return (0);
}
