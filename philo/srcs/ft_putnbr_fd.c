/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:08:01 by vabertau          #+#    #+#             */
/*   Updated: 2024/05/24 18:24:18 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	l;

	l = (long)n;
	if (l < 0)
	{
		write(fd, "-", 1);
		l = -l;
	}
	if (l > 9)
		ft_putnbr_fd(l / 10, fd);
	ft_putchar_fd((l % 10) + 48, fd);
}
/*
#include <stdio.h>

int	main(void)
{
	ft_putnbr_fd(0, 1);
}*/
