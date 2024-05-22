/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setflags_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:50:10 by vabertau          #+#    #+#             */
/*   Updated: 2024/05/22 19:03:42 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	search_dead(t_philosopher *philosopher)
{
	int	i;

	i = 0;
	while (i < philosopher->data->nb_philos)
	{
		pthread_mutex_lock(philosopher->mutex_write);
		ft_printf("t_lastmeal = %i\n", philosopher[i].t_lastmeal);
		ft_printf("get_time = %i\n", get_time());
		ft_printf("get_time - t_lastmeal = %i\n", get_time() - philosopher[i].t_lastmeal);
		ft_printf("t_tdie = %i\n", philosopher[i].data->t_tdie);
		ft_printf("dies ? = %i\n", get_time() - philosopher[i].t_lastmeal > philosopher[i].data->t_tdie);
			pthread_mutex_unlock(philosopher->mutex_write);
		if (get_time() - philosopher[i].t_lastmeal > philosopher[i].data->t_tdie)
		{
			pthread_mutex_lock(philosopher->mutex_endflag);
			print_died(&(philosopher[i]));
			philosopher[i].data->end_flag = 1;
			pthread_mutex_unlock(philosopher->mutex_endflag);
			break ;
		}
		i++;
	}
}

void	*setflags_routine(void *philosopher)
{
	t_data	*data = ((t_philosopher *)philosopher)->data;
	while (!data->end_flag)
	{
		search_dead((t_philosopher *)philosopher);
	}
	return (philosopher);
}
