/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:25:15 by vabertau          #+#    #+#             */
/*   Updated: 2024/05/22 19:05:09 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/*
Giving access to data to each philosopher (needed for access to t_teat, etc)

Giving access to mutexes for left and right forks to each philosopher

Giving access to mutex_write to each philosopher (using mutex 200)

Setting indexes

Initializating first meal at get_time
*/

void	init_philosopher(t_data *data, t_philosopher *philosopher, pthread_mutex_t *mutex)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		(philosopher[i]).data = data;
		//(philosopher[i]).mutex = mutex;
		(philosopher[i]).mutex_rfork = &(mutex[i]);
		if (i + 1 < data->nb_philos)
			(philosopher[i]).mutex_lfork = &(mutex[i + 1]);
		else
			(philosopher[i]).mutex_lfork = &(mutex[0]);
		(philosopher[i]).mutex_write = &(mutex[200]);
		(philosopher[i]).index = i;
		(philosopher[i]).t_lastmeal = get_time(); // != start time in data bc of exec time ?
		(philosopher[i]).mutex_endflag = &(mutex[201]);
		i++;
	}
}
