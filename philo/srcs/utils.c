/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:34:26 by inwagner          #+#    #+#             */
/*   Updated: 2023/09/21 20:37:33 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(int status)
{
	if (!status)
		printf("Died.\n");
	if (status == 1)
		printf("Eating.\n");
	if (status == 2)
		printf("Sleeping.\n");
	if (status == 3)
		printf("Thinking.\n");
	if (status == 4)
		printf("Holding Left Fork\n");
	if (status == 5)
		printf("Holding Right Fork\n");
}
