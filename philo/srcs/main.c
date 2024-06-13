/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:55:59 by vabertau          #+#    #+#             */
/*   Updated: 2024/05/24 18:29:01 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_data			data;
	pthread_mutex_t	mutex[204];
	t_philosopher	philosopher[200];

	if (check_arg(argc, argv) == -1)
		return (-1);
	init_data(argc, argv, &data);
	init_mutex(&data, mutex);
	init_philosopher(&data, philosopher, mutex);
	if (launch_threads(&data, philosopher, mutex) == -1)
		return (-1);
	destroy_mutex(data, mutex);
}
