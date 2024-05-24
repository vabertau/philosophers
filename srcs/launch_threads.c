/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:36:56 by vabertau          #+#    #+#             */
/*   Updated: 2024/05/24 17:05:13 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ret_endflag(t_philosopher *philosopher)
{
	int	ret;

	pthread_mutex_lock(philosopher->mutex_endflag); // not useful ? only reading
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
philo_routine launches first uneven philosophers then
even philosophers, to prevent fork blocks.

It then enters an infinite loop of eat sleep think,
	broken only if endflag is set to 1 by setflags_routine.
Also, actions are not executed if endflag has been set to 1,
	to avoid sleeping and thinking if a death occurs after eating.

*/

void	*philo_routine(void *philosopher)
{
	t_philosopher	*tmp;

	tmp = (t_philosopher *)philosopher;
	if (tmp->index % 2 == 0)
		ft_usleep(1);
	while (!ret_endflag(tmp))
	{
		eat(tmp);
		ft_sleep(tmp);
		think(tmp);
		// ft_printf("end_flag = %i\n", tmp->data->end_flag);
	}
	return (philosopher);
}

/*
Lauching set_flag thread with set flag routine function. Checks in an infinite loop if a philo is dead or if
all philos have reached max_meals of more,
	if it happens breaks the loop and sets endflag to 1. Endflag will then stop
philo threads (stopping thread loop + preventing entering actions).

Launching a thread for each philosopher

Creates each philosopher's thread calling philo_routine. philo_routine launches first uneven philosophers then
even philosophers, to prevent fork blocks.

It then enters an infinite loop of eat sleep think,
	broken only if endflag is set to 1 by setflags_routine.
Also, actions are not executed if endflag has been set to 1,
	to avoid sleeping and thinking if a death occurs after eating.

Calling pthread_join to wait for the end of processes
*/

void	launch_threads(t_data *data, t_philosopher *philosopher,
		pthread_mutex_t *mutex)
{
	pthread_t	mainthread_id;
	int			i;

	(void)mutex;
	i = 0;
	if (pthread_create(&mainthread_id, NULL, &setflags_routine,
			philosopher) != 0)
		return ((void)destroy_mutex(*data, mutex),
			(void)ft_printf("pthread_create error\n"), (void)exit(-1));
	while (i < data->nb_philos)
	{
		if (pthread_create(&(philosopher[i].thread_id), NULL, &philo_routine,
				&(philosopher[i])) != 0)
			return (thread_create_error(i, philosopher, mutex, mainthread_id));
		i++;
	}
	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_join(philosopher[i].thread_id, NULL) != 0)
			return (thread_join_error(philosopher, mutex));
		i++;
	}
	if (pthread_join(mainthread_id, NULL) != 0)
		return (thread_join_error(philosopher, mutex));
}
