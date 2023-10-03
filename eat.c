/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:48:03 by jralph            #+#    #+#             */
/*   Updated: 2023/10/03 21:04:10 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_recup_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->fork_left);
		if (philo->global->nb_philo > 1)
			pthread_mutex_lock(philo->fork_right);
		else
		{
			pthread_mutex_unlock(philo->fork_left);
			return (1);
		}
	}
	else
	{
		pthread_mutex_lock(philo->fork_right);
		pthread_mutex_lock(philo->fork_left);
	}
	return (0);
}

static void	ft_print_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->global->print);
	printf("%lld %d %s", timestamp(), philo->id, " has taken a fork");
	printf("%lld %d %s", timestamp(), philo->id, " has taken a fork");
	printf("%lld %d %s", timestamp(), philo->id, " is eating");
	pthread_mutex_unlock(&philo->global->print);
}

void	ft_eat(t_philo *philo)
{
	ft_recup_fork(philo);
	ft_print_eat(philo);
	ft_usleep(philo->global->t_eat);
	philo->last_eat = timestamp();
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
}
