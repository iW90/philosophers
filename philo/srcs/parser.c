/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:11:24 by inwagner          #+#    #+#             */
/*   Updated: 2023/09/23 19:21:33 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_table(int total)
{
	t_plate	**table;
	t_plate	*plate;
	int		i;

	table = malloc(sizeof(t_plate *) * total);
	if (!table)
		return (end_dinner(2));
	call_butler()->table = table;
	plate = malloc(sizeof(t_plate) * total);
	if (!plate)
		return (end_dinner(2));
	i = -1;
	while (++i < total)
	{
		plate[i] = (t_plate){0};
		table[i] = &plate[i];
	}
	return (0);
}
