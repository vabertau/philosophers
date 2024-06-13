/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:31:01 by vabertau          #+#    #+#             */
/*   Updated: 2024/06/13 14:52:00 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	check_digit(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (-1);
		i++;
	}
	return (0);
}

int	check_arg(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (ft_printf("usage: ./philosophers \
		number_of_philosophers \
		time_to_die time_to_eat time_to_sleep \
		[number_of_times_each_philosopher_must_eat]\n"),
			-1);
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 200
		|| check_digit(argv[1]) == -1)
		return (ft_printf("Please enter a number of \
		philosophers between 1 and 200\n"), -1);
	if (ft_atoi(argv[2]) < 1 || check_digit(argv[2]) == -1)
		return (ft_printf("Please enter a time to die > 0\n"), -1);
	if (ft_atoi(argv[3]) < 1 || check_digit(argv[3]) == -1)
		return (ft_printf("Please enter a time to eat > 0\n"), -1);
	if (ft_atoi(argv[4]) < 1 || check_digit(argv[4]) == -1)
		return (ft_printf("Please enter a time to sleep > 0\n"), -1);
	if (argv[5] && (ft_atoi(argv[5]) < 1 || check_digit(argv[4]) == -1))
		return (ft_printf("Please enter a max meal number > 0\n"), -1);
	return (0);
}
