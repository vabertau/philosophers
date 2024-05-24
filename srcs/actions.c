/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:19:37 by vabertau          #+#    #+#             */
/*   Updated: 2024/05/24 18:30:27 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
philosopher->fork in use is used to know if the mute
 is still locked when a philosopher dies.
If it is the case, mutex should be unlocked, ok thread will continue,
*/

#include "../includes/philosophers.h"

void	eat(t_philosopher *philosopher)
{
	if (philosopher->data->end_flag == 1)
		return ;
	pthread_mutex_lock(philosopher->mutex_lfork);
	print_fork(philosopher);
	if (philosopher->data->nb_philos == 1)
	{
		pthread_mutex_unlock(philosopher->mutex_lfork);
		ft_usleep(philosopher->data->t_tdie + 10);
		return ;
	}
	pthread_mutex_lock(philosopher->mutex_rfork);
	print_fork(philosopher);
	print_eat(philosopher);
	pthread_mutex_lock(philosopher->mutex_tlastmeal);
	philosopher->t_lastmeal = get_time();
	philosopher->count_meals++;
	pthread_mutex_unlock(philosopher->mutex_tlastmeal);
	ft_usleep(philosopher->data->t_teat);
	pthread_mutex_unlock(philosopher->mutex_lfork);
	pthread_mutex_unlock(philosopher->mutex_rfork);
}

void	ft_sleep(t_philosopher *philosopher)
{
	if (philosopher->data->end_flag == 1 || philosopher->data->nb_philos == 1)
		return ;
	print_sleep(philosopher);
	ft_usleep(philosopher->data->t_tsleep);
}

void	think(t_philosopher *philosopher)
{
	if (philosopher->data->end_flag == 1 || philosopher->data->nb_philos == 1)
		return ;
	print_think(philosopher);
}
