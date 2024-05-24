/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:05:03 by vabertau          #+#    #+#             */
/*   Updated: 2024/05/24 17:05:18 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	thread_create_error(int threads_launched, t_philosopher *philosopher,
		pthread_mutex_t *mutex, int mainthread_id)
{
	int	i;

	i = 0;
	ft_printf("pthread_create error\n");
	pthread_join(mainthread_id, NULL);
	while (i < threads_launched)
	{
		pthread_join(philosopher[i].thread_id, NULL);
		i++;
	}
	destroy_mutex(*(philosopher[0].data), mutex);
	exit(-1);
}

void	thread_join_error(t_philosopher *philosopher, pthread_mutex_t *mutex)
{
	ft_printf("pthread_join error\n");
	destroy_mutex(*(philosopher[0].data), mutex);
	exit(-1);
}
