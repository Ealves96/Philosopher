/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:50:23 by ealves            #+#    #+#             */
/*   Updated: 2023/10/03 14:16:57 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_death(t_philo *philo)
{
	int	res;

	res = philo->global->t_eat - philo->last_eat;
	pthread_mutex_lock(&philo->global->dead_check);
	if (res <= 0)
	{
		pthread_mutex_unlock(&philo->global->dead_check);
		return (1);
	}
	pthread_mutex_unlock(&philo->global->dead_check);
	return (0);
}

void	*check_death(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	ft_usleep(philo->global->t_death + 1, philo->global);
	// pthread_mutex_lock(&philo->global->m_eat);
	// pthread_mutex_lock(&philo->global->m_stop);
	if (!(is_death(philo) == 0) && timestamp() - \
			philo->last_eat >= (long)(philo->global->t_death))
	{
		// pthread_mutex_unlock(&philo->global->m_eat);
		// pthread_mutex_unlock(&philo->global->m_stop);
		// print_msg(philo, " is dead\n");
		is_death(philo);
	}
	// pthread_mutex_unlock(&philo->global->m_eat);
	// pthread_mutex_unlock(&philo->global->m_stop);
	return (NULL);
}
