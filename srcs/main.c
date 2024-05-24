/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:55:59 by vabertau          #+#    #+#             */
/*   Updated: 2024/05/24 15:35:51 by vabertau         ###   ########.fr       */
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
	pthread_mutex_t mutex[204];
	t_philosopher	philosopher[200];

	if (argc != 5 && argc != 6)
		return (ft_printf("usage: ./philosophers number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n"), -1);
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 200)
		return (ft_printf("Please enter a number of philosophers between 1 and 200\n"));
	init_data(argc, argv, &data);
	init_mutex(&data, mutex);
	init_philosopher(&data, philosopher, mutex);
	launch_threads(&data, philosopher, mutex);
	destroy_mutex(data, mutex);
}
