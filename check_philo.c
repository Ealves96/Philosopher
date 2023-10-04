/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:50:23 by ealves            #+#    #+#             */
/*   Updated: 2023/10/04 18:27:27 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_stop(t_global *global)
{
	int	stop;

	pthread_mutex_lock(&global->dead_check);
	stop = global->stop_thread;
	pthread_mutex_unlock(&global->dead_check);
	return (stop);
}

int	check_death(t_global *global)
{
	t_philo			philo;
	unsigned int	i;
	long long int	time;

	i = -1;
	time = timestamp();
	while (++i < global->nb_philo)
	{
		philo = global->philo[i];
		if (time - philo.last_eat >= global->t_death)
		{
			global->stop_thread = 1;
			printf("%lld %d %s\n", time, philo.id, "is dead");
			return (1);
		}
	}
	return (0);
}

int	check_nb_eat(t_global *global)
{
	t_philo				philo;
	unsigned int		i;

	i = 0;
	while (i < global->nb_philo)
	{
		philo = global->philo[i];
		if (global->nb_eat == -1)
			return (1);
		if (global->nb_eat > philo.nb_eat)
			return (1);
		i++;
	}
	global->stop_thread = 1;
	return (0);
}
