/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:37:40 by vabertau          #+#    #+#             */
/*   Updated: 2024/05/24 16:50:24 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/*
Initiates data struct :

- fills data with global data :
  - nb_philos, t_tdie, t_teat t_tsleep, max_meals using argv
  - t_tstart using get_time
*/
void	init_data(int argc, char **argv, t_data *data)
{
	data->nb_philos = ft_atoi(argv[1]);
	data->t_tdie = ft_atoi(argv[2]);
	data->t_teat = ft_atoi(argv[3]);
	data->t_tsleep = ft_atoi(argv[4]);
	data->t_start = get_time();
	data->end_flag = 0;
	if (argc == 6)
		data->max_meals = ft_atoi(argv[5]);
	else
		data->max_meals = -1;
}
