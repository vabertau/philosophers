/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:22:21 by vabertau          #+#    #+#             */
/*   Updated: 2024/05/24 18:14:57 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	ret;
	int	sign;

	i = 0;
	ret = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		ret = ret * 10 + nptr[i] - 48;
		i++;
	}
	return (ret * sign);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("return = %d\n", ft_atoi("123"));
}*/
