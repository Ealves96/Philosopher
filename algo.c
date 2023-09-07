/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:13:55 by ealves            #+#    #+#             */
/*   Updated: 2023/09/07 12:43:17 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(t_philo *philo)
{
	print_msg(philo, "is sleeping\n");
	ft_usleep(philo->global->t_sleep);
}

void	ft_eat(t_philo *philo)
{
	print_msg(philo, "is eating\n");
	ft_usleep(philo->global->t_eat);
	pthread_mutex_unlock(&philo->global->all_fork[philo->id]);
	print_msg(philo, "dropped a fork\n");
	if (philo->id == philo->global->nb_philo - 1)
		pthread_mutex_unlock(&philo->global->all_fork[0]);
	else
		pthread_mutex_unlock(&philo->global->all_fork[philo->id + 1]);
	print_msg(philo, "dropped a fork\n");
	philo->last_eat = timestamp();
	ft_sleep(philo);
}

void	ft_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->global->all_fork[philo->id]);
	print_msg(philo, "is taking fork\n");
	if (philo->id == philo->global->nb_philo - 1)
		pthread_mutex_lock(&philo->global->all_fork[0]);
	else
		pthread_mutex_lock(&philo->global->all_fork[philo->id + 1]);
	print_msg(philo, "is taking fork\n");
	ft_eat(philo);
}

void	*p_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	philo->state = 0;
	while (1)
	{
		ft_fork(philo);
		print_msg(philo, "is thinking\n");
	}
	return (NULL);
}
