/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:36:56 by vabertau          #+#    #+#             */
/*   Updated: 2024/05/22 14:39:54 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*main_routine(void *philosopher)
{
	(void)philosopher;
	return (philosopher);
}

void	*philo_routine(void *philosopher)
{
	t_philosopher *tmp;

	tmp = (t_philosopher *)philosopher;
	while (1)
	{
		eat(tmp);
		ft_sleep(tmp);
		think(tmp);
	}
	return (philosopher);
}

void	launch_threads(t_data *data, t_philosopher *philosopher, pthread_mutex_t *mutex)
{
	pthread_t	mainthread_id;
	int			i;

	(void)mutex;
	i = 0;
	pthread_create(&mainthread_id, NULL, &main_routine, philosopher);
	//protect
	while (i < data->nb_philos)
	{
		pthread_create(&(philosopher[i].thread_id), NULL, &philo_routine, &(philosopher[i]));
		// protect
		i++;
	}
	i = 0;
	while (i < data->nb_philos)
	{
		pthread_join(philosopher[i].thread_id, NULL);
		// protect
		i++;
	}
	//pthread join calls to wait for threads to end
}
