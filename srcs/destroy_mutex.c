/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:48:32 by vabertau          #+#    #+#             */
/*   Updated: 2024/05/24 10:56:37 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	destroy_mutex(t_data data, pthread_mutex_t *mutex)
{
	int	i;

	i = 0;
	while (i < data.nb_philos + 3)
	{
		pthread_mutex_destroy(&(mutex[i]));
		i++;
	}
}
