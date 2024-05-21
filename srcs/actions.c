/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:19:37 by vabertau          #+#    #+#             */
/*   Updated: 2024/05/21 15:38:01 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	eat(t_philosopher *philosopher)
{
	ft_printf("is eating");
	sleep(philosopher->data->t_teat);
}

void	ft_sleep(t_philosopher *philosopher)
{
	ft_printf("is sleeping");
	sleep(philosopher->data->t_tsleep);
}

void	think(void)
{
	ft_printf("is thinking");
}
