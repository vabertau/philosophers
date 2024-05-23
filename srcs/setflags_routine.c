/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setflags_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:50:10 by vabertau          #+#    #+#             */
/*   Updated: 2024/05/23 19:55:39 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	search_dead(t_philosopher *philosopher)
{
	int	i;

	i = 0;
	while (i < philosopher->data->nb_philos)
	{
		//pthread_mutex_lock(philosopher->mutex_endflag);
		//if (philosopher[i].data->end_flag == 1)
		//	break ;
		//pthread_mutex_unlock(philosopher->mutex_endflag);
		/*pthread_mutex_lock(philosopher->mutex_write);
		ft_printf("t_lastmeal = %i\n", philosopher[i].t_lastmeal);
		ft_printf("get_time = %i\n", get_time());
		ft_printf("get_time - t_lastmeal = %i\n", get_time() - philosopher[i].t_lastmeal);
		ft_printf("t_tdie = %i\n", philosopher[i].data->t_tdie);
		ft_printf("dies ? = %i\n", get_time() - philosopher[i].t_lastmeal > philosopher[i].data->t_tdie);
		pthread_mutex_unlock(philosopher->mutex_write);*/
		pthread_mutex_lock(philosopher->mutex_tlastmeal);
		//unsigned long long time;

		//time = get_time() - philosopher->data->t_start;
		//ft_printf("time bf death = %i \n", time);
		if (get_time() - philosopher[i].t_lastmeal > philosopher[i].data->t_tdie)
		{
			pthread_mutex_unlock(philosopher->mutex_tlastmeal);
			//pthread_mutex_lock(philosopher->mutex_write);
			print_died(&(philosopher[i]));
			//pthread_mutex_unlock(philosopher->mutex_write);
			//pthread_mutex_lock(philosopher->mutex_endflag);
			philosopher[i].data->end_flag = 1;
			//pthread_mutex_unlock(philosopher->mutex_endflag);
			//pthread_mutex_unlock(philosopher->mutex_write);
			break ;
		}
		else
			pthread_mutex_unlock(philosopher->mutex_tlastmeal);
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
