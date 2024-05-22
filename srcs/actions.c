/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:19:37 by vabertau          #+#    #+#             */
/*   Updated: 2024/05/22 14:50:41 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	eat(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->mutex_lfork);
	pthread_mutex_lock(philosopher->mutex_rfork);
	print_fork(philosopher);
	usleep(philosopher->data->t_teat * 1000);
	pthread_mutex_unlock(philosopher->mutex_lfork);
	pthread_mutex_unlock(philosopher->mutex_rfork);
}

void	ft_sleep(t_philosopher *philosopher)
{
	print_sleep(philosopher);
	usleep(philosopher->data->t_tsleep * 1000);
}

void	think(t_philosopher *philosopher)
{
	print_think(philosopher);
}
