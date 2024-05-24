/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:55:59 by vabertau          #+#    #+#             */
/*   Updated: 2024/05/24 10:56:30 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
/*
int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
		return (ft_printf("usage: ./philosophers number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n"), -1);
	init_data(argv, &data);
}
*/
// ==== TEST INIT_DATA ====

int	main(int argc, char **argv)
{
	t_data	data;
	pthread_mutex_t mutex[203];
	t_philosopher	philosopher[200];

	if (argc != 5 && argc != 6)
		return (ft_printf("usage: ./philosophers number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n"), -1);
	init_data(argv, &data);

	ft_printf("data.nb_philos = %i\n", data.nb_philos);
	ft_printf("data.t_tdie = %i\n", data.t_tdie);
	ft_printf("data.t_teat = %i\n", data.t_teat);
	ft_printf("data.t_tsleep = %i\n", data.t_tsleep);
	ft_printf("data.nb_teat = %i\n", data.nb_teat);

	init_mutex(&data, mutex);
	init_philosopher(&data, philosopher, mutex);
	launch_threads(&data, philosopher, mutex);
	destroy_mutex(data, mutex);
}
