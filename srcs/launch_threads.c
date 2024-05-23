/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:36:56 by vabertau          #+#    #+#             */
/*   Updated: 2024/05/23 19:40:55 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ret_endflag(t_philosopher *philosopher)
{
	int	ret;
pthread_mutex_lock(philosopher->mutex_endflag);
	ret = philosopher->data->end_flag;
pthread_mutex_unlock(philosopher->mutex_endflag);
	return (ret);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < milliseconds)
		usleep(50);
	return (0);
}

/*
Philosopher with even indexes wait for 1 ms so that philosopher sitting next to each other do not all take one fork which would block

Philosophers alternatively eat, sleep, think
*/

void	*philo_routine(void *philosopher)
{
	t_philosopher *tmp;

	tmp = (t_philosopher *)philosopher;
	if (tmp->index % 2 == 0)
		ft_usleep(1);
	while (!ret_endflag(tmp))
	{
		eat(tmp);
		ft_sleep(tmp);
		think(tmp);
		//ft_printf("end_flag = %i\n", tmp->data->end_flag);
	}
	return (philosopher);
}

void	launch_threads(t_data *data, t_philosopher *philosopher, pthread_mutex_t *mutex)
{
	pthread_t	mainthread_id;
	int			i;

	(void)mutex;
	i = 0;
	pthread_create(&mainthread_id, NULL, &setflags_routine, philosopher);
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
	pthread_join(mainthread_id, NULL);
	//pthread join calls to wait for threads to end
}
