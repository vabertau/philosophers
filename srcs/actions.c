/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:19:37 by vabertau          #+#    #+#             */
/*   Updated: 2024/05/23 20:42:10 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
philosopher->fork in use is used to know if the mutex is still locked when a philosopher dies.
If it is the case, mutex should be unlocked, ok thread will continue,
*/

#include "../includes/philosophers.h"

void	eat(t_philosopher *philosopher)
{
	if (philosopher->data->end_flag == 1)
		return ;
	pthread_mutex_lock(philosopher->mutex_lfork);
	print_fork(philosopher);
	pthread_mutex_lock(philosopher->mutex_rfork);
	print_fork(philosopher);
	pthread_mutex_lock(philosopher->mutex_tlastmeal);
	philosopher->t_lastmeal = get_time();
	pthread_mutex_unlock(philosopher->mutex_tlastmeal);
	print_eat(philosopher);
	ft_usleep(philosopher->data->t_teat);
	pthread_mutex_unlock(philosopher->mutex_lfork);
	pthread_mutex_unlock(philosopher->mutex_rfork);
}

void	ft_sleep(t_philosopher *philosopher)
{
	if (philosopher->data->end_flag == 1)
		return ;
	print_sleep(philosopher);
	ft_usleep(philosopher->data->t_tsleep);
}

void	think(t_philosopher *philosopher)
{
	if (philosopher->data->end_flag == 1)
		return ;
	print_think(philosopher);
}
