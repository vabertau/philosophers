/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:20:25 by vabertau          #+#    #+#             */
/*   Updated: 2024/05/22 14:28:44 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	print_fork(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->mutex_write);
	ft_printf("%i has taken a fork\n", philosopher->index);
	pthread_mutex_unlock(philosopher->mutex_write);
}

void	print_sleep(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->mutex_write);
	ft_printf("%i is sleeping\n", philosopher->index);
	pthread_mutex_unlock(philosopher->mutex_write);
}

void	print_think(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->mutex_write);
	ft_printf("%i is thinking\n", philosopher->index);
	pthread_mutex_unlock(philosopher->mutex_write);
}
