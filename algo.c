/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:13:55 by ealves            #+#    #+#             */
/*   Updated: 2023/10/03 17:12:20 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(t_philo *philo)
{
	print_msg(philo, "is sleeping\n");
	ft_usleep(philo->global->t_sleep, philo->global);
}

void	ft_eat(t_philo *philo)
{
	print_msg(philo, "is eating\n");
	philo->last_eat = timestamp();
	ft_usleep(philo->global->t_eat, philo->global);
	pthread_mutex_unlock(philo->fork_left);
	print_msg(philo, "dropped a fork\n");
	pthread_mutex_unlock(philo->fork_right);
	print_msg(philo, "dropped a fork\n");
}

// nmb philo impair commencent a manger en prenant la fork gauche en 1er
int	ft_recup_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->fork_left);
		print_msg(philo, "is taking fork\n");
		if (philo->global->nb_philo > 1)
		{
			pthread_mutex_lock(philo->fork_right);
			print_msg(philo, "is taking fork\n");
		}
		else
		{
			pthread_mutex_unlock(philo->fork_left);
			return (1);
		}
	}
	else
	{
		pthread_mutex_lock(philo->fork_right);
		print_msg(philo, "is taking fork\n");
		pthread_mutex_lock(philo->fork_left);
		print_msg(philo, "is taking fork\n");
	}
	return (0);
}

// si nmb philo pair > attendent avant de pouvoir prendre des forks
void	*p_routine(void *data)
{
	t_philo			*philo;
	// unsigned int	i;

	// i = 0;

	philo = (t_philo *)data;
	philo->status = 0;
	if (philo->id % 2 == 0)
		ft_usleep(0.25 * philo->global->t_eat, philo->global);
	while (is_death(philo) == 0)
	{
		check_death(data);
		ft_recup_fork(philo);
		ft_eat(philo);
		ft_sleep(philo);
		print_msg(philo, "is thinking\n");
	}
	if (is_death(philo) == 1)
		print_msg(philo, "is dead\n");
	return (NULL);
}
