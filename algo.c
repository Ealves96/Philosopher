/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:13:55 by ealves            #+#    #+#             */
/*   Updated: 2023/10/04 19:33:48 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_sleep(t_philo *philo)
{
	if (check_stop(philo->global))
		return (1);
	print_msg(philo, "is sleeping");
	ft_usleep(philo->global->t_sleep);
	return (0);
}

static int	ft_think(t_philo *philo)
{
	if (check_stop(philo->global))
		return (1);
	print_msg(philo, "is thinking");
	if (philo->global->nb_philo % 2 == 1)
		usleep((philo->global->t_death - philo->global->t_eat
				- philo->global->t_sleep) * 700);
	return (0);
}

// si nmb philo pair > attendent avant de pouvoir prendre des forks
void	*p_routine(void *data)
{
	t_philo			*philo;

	philo = (t_philo *)data;
	if (philo->id % 2 == 0)
		ft_usleep(0.5 * philo->global->t_eat);
	while (1)
	{
		if (ft_eat(philo))
			break ;
		if (ft_sleep(philo))
			break ;
		if (ft_think(philo))
			break ;
	}
	return (data);
}
