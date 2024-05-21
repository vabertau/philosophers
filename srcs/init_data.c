/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:37:40 by vabertau          #+#    #+#             */
/*   Updated: 2024/05/21 12:21:42 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/*
Initiates data struct :

- fills data with argv : nb_philos, t_tdie, t_teatm t_tsleep, nb_teat
*/
void	init_data(char **argv, t_data *data)
{
	data->nb_philos = ft_atoi(argv[1]);
	data->t_tdie = ft_atoi(argv[2]);
	data->t_teat = ft_atoi(argv[3]);
	data->t_tsleep = ft_atoi(argv[4]);
	if (argv[5])
		data->nb_teat = ft_atoi(argv[5]);
	else
		data->nb_teat = -1;

}
