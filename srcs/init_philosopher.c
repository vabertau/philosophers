/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:25:15 by vabertau          #+#    #+#             */
/*   Updated: 2024/05/24 18:29:36 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/*
Initializes the philosopher struct:

Giving access to data to each philosopher

Giving access to mutexes for left and right forks to each philosopher

Giving access to mutex_write, mutex_endflag, mutex_tlastmeal to all philosophers

Giving an index to philosophers

Initializing last_meal at get_time
*/

void	init_philosopher(t_data *data, t_philosopher *philosopher,
		pthread_mutex_t *mutex)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		(philosopher[i]).data = data;
		(philosopher[i]).mutex_rfork = &(mutex[i]);
		if (i + 1 < data->nb_philos)
			(philosopher[i]).mutex_lfork = &(mutex[i + 1]);
		else
			(philosopher[i]).mutex_lfork = &(mutex[0]);
		(philosopher[i]).mutex_write = &(mutex[data->nb_philos]);
		(philosopher[i]).index = i;
		(philosopher[i]).t_lastmeal = get_time();
		(philosopher[i]).mutex_endflag = &(mutex[data->nb_philos + 1]);
		(philosopher[i]).mutex_tlastmeal = &(mutex[data->nb_philos + 2]);
		(philosopher[i]).count_meals = 0;
		i++;
	}
}
