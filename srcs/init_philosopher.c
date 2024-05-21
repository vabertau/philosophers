/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:25:15 by vabertau          #+#    #+#             */
/*   Updated: 2024/05/21 15:37:02 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	init_philosopher(t_data *data, t_philosopher *philosopher)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		(philosopher[i]).data = data;
		i++;
	}
}
