/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:13:55 by ealves            #+#    #+#             */
/*   Updated: 2023/10/03 21:17:22 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(t_philo *philo)
{
	print_msg(philo, "is sleeping");
	ft_usleep(philo->global->t_sleep);
}

// si nmb philo pair > attendent avant de pouvoir prendre des forks
void	*p_routine(void *data)
{
	t_philo			*philo;

	philo = (t_philo *)data;
	philo->nb_eat = 0;
	if (philo->id % 2 == 0)
		ft_usleep(0.25 * philo->global->t_eat);
	while (1)
	{
		if (check_stop(philo->global))
			break ;
		ft_recup_fork(philo);
		ft_eat(philo);
		if (check_stop(philo->global))
			break ;
		ft_sleep(philo);
		if (check_stop(philo->global))
			break ;
		print_msg(philo, "is thinking");
	}
	return (NULL);
}
