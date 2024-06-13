/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:02:09 by vabertau          #+#    #+#             */
/*   Updated: 2024/05/24 18:29:17 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/*
Calls	pthreads_mutex_init(void) the same nb of times as the nb
of philosophers to initialize
the mutexes for forks, + 3 for mutex_write, mutex_endflag, mutex_tlastmeal
*/

void	init_mutex(t_data *data, pthread_mutex_t *mutex)
{
	int	i;

	i = 0;
	while (i < data->nb_philos + 3)
	{
		pthread_mutex_init(&(mutex[i]), NULL);
		i++;
	}
}
