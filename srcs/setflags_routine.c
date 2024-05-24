/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setflags_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:50:10 by vabertau          #+#    #+#             */
/*   Updated: 2024/05/24 15:44:58 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	search_dead(t_philosopher *philosopher)
{
	int	i;

	i = 0;
	while (i < philosopher->data->nb_philos)
	{
		//pthread_mutex_lock(philosopher->mutex_tlastmeal); // not useful ? cause only reading
		if (get_time() - philosopher[i].t_lastmeal > philosopher[i].data->t_tdie)
		{
			//pthread_mutex_unlock(philosopher->mutex_tlastmeal);
			pthread_mutex_lock(philosopher->mutex_endflag);
			philosopher[i].data->end_flag = 1;
			pthread_mutex_unlock(philosopher->mutex_endflag);
			print_died(&(philosopher[i]));
			//pthread_mutex_unlock(philosopher->mutex_write);
			//pthread_mutex_lock(philosopher->mutex_endflag);
			//pthread_mutex_unlock(philosopher->mutex_endflag);
			//pthread_mutex_unlock(philosopher->mutex_write);
			break ;
		}
		else
			pthread_mutex_unlock(philosopher->mutex_tlastmeal);
		i++;
	}
}

void	search_maxmeals(t_philosopher *philosopher)
{
	int	i;

	i = 0;
	while (i < philosopher[0].data->nb_philos)
	{
		if (philosopher[i].count_meals < philosopher[0].data->max_meals)
			return ;
		else
			i++;
	}
	philosopher[0].data->end_flag = 1;
}

/* Checks in an infinite loop if a philo is dead or if
all philos have reached max_meals of more, if it happens breaks the loop
and sets endflag to 1. Endflag will then stop
philo threads (stopping thread loop + preventing entering actions).*/

void	*setflags_routine(void *philosopher)
{
	t_data	*data = ((t_philosopher *)philosopher)->data;
	while (!data->end_flag)
	{
		search_dead((t_philosopher *)philosopher);
		if (data->max_meals != -1)
			search_maxmeals((t_philosopher *)philosopher);
	}
	return (philosopher);
}
