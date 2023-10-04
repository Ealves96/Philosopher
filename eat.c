/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:48:03 by jralph            #+#    #+#             */
/*   Updated: 2023/10/04 18:47:24 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_recup_fork(t_philo *philo)
{
	if (philo->global->nb_philo == 1)
		return ;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->fork_left);
		pthread_mutex_lock(philo->fork_right);
	}
	else
	{
		pthread_mutex_lock(philo->fork_right);
		pthread_mutex_lock(philo->fork_left);
	}
}

static void	ft_print_eat(t_philo *philo)
{
	if (philo->global->nb_philo == 1)
		return (print_msg(philo, "has taken a fork"));
	pthread_mutex_lock(&philo->global->dead_check);
	printf("%lld %d %s\n", timestamp(), philo->id, " has taken a fork");
	printf("%lld %d %s\n", timestamp(), philo->id, " has taken a fork");
	printf("%lld %d %s\n", timestamp(), philo->id, " is eating");
	pthread_mutex_unlock(&philo->global->dead_check);
}

int	ft_eat(t_philo *philo)
{
	ft_recup_fork(philo);
	if (check_stop(philo->global))
	{
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
		return (1);
	}
	ft_print_eat(philo);
	ft_usleep(philo->global->t_eat);
	if (philo->global->nb_philo > 1)
	{
		pthread_mutex_lock(&philo->global->dead_check);
		philo->last_eat = timestamp();
		philo->nb_eat++;
		pthread_mutex_unlock(&philo->global->dead_check);
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
	}
	return (0);
}
