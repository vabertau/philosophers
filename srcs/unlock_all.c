/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlock_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:38:17 by vabertau          #+#    #+#             */
/*   Updated: 2024/05/23 20:39:36 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	unlock_all(t_philosopher *philosopher)
{
	int	i;

	i = 0;
	while (i < philosopher[0].data->nb_philos)
	{
		if (philosopher->lfork_locked == 0)
			
		philosopher->rfork_locked = 0;
		i++;
	}
}
