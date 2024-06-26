/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:20:25 by vabertau          #+#    #+#             */
/*   Updated: 2024/05/24 18:30:49 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	print_fork(t_philosopher *philosopher)
{
	unsigned long long	time;

	if (!philosopher->data->end_flag)
	{
		pthread_mutex_lock(philosopher->mutex_write);
		time = get_time() - philosopher->data->t_start;
		ft_printf("%i %i has taken a fork\n", time, philosopher->index);
		pthread_mutex_unlock(philosopher->mutex_write);
	}
}

void	print_sleep(t_philosopher *philosopher)
{
	unsigned long long	time;

	if (!philosopher->data->end_flag)
	{
		pthread_mutex_lock(philosopher->mutex_write);
		time = get_time() - philosopher->data->t_start;
		ft_printf("%i %i is sleeping\n", time, philosopher->index);
		pthread_mutex_unlock(philosopher->mutex_write);
	}
}

void	print_think(t_philosopher *philosopher)
{
	unsigned long long	time;

	if (!philosopher->data->end_flag)
	{
		pthread_mutex_lock(philosopher->mutex_write);
		time = get_time() - philosopher->data->t_start;
		ft_printf("%i %i is thinking\n", time, philosopher->index);
		pthread_mutex_unlock(philosopher->mutex_write);
	}
}

void	print_eat(t_philosopher *philosopher)
{
	unsigned long long	time;

	if (!philosopher->data->end_flag)
	{
		pthread_mutex_lock(philosopher->mutex_write);
		time = get_time() - philosopher->data->t_start;
		ft_printf("%i %i is eating\n", time, philosopher->index);
		pthread_mutex_unlock(philosopher->mutex_write);
	}
}

void	print_died(t_philosopher *philosopher)
{
	unsigned long long	time;

	pthread_mutex_lock(philosopher->mutex_write);
	time = philosopher->t_lastmeal + philosopher->data->t_tdie
		- philosopher->data->t_start;
	ft_printf("%i %i died\n", time, philosopher->index);
	pthread_mutex_unlock(philosopher->mutex_write);
}
