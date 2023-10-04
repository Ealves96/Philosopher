/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:49:32 by ealves            #+#    #+#             */
/*   Updated: 2023/10/04 19:33:13 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_philo(t_global *global)
{
	t_philo			philo;
	unsigned int	i;

	i = 0;
	while (i < global->nb_philo)
	{
		philo = global->philo[i];
		philo.id = i + 1;
		philo.last_eat = 0;
		philo.nb_eat = 0;
		i++;
	}
	return (0);
}

void	ft_usleep(long int time)
{
	long int	curr_time;

	curr_time = ft_gettimeofday();
	while ((ft_gettimeofday() - curr_time) < time)
		usleep(time / 10);
}

static int	init_mutex(t_global *global)
{
	unsigned int	i;

	i = 0;
	while (i < global->nb_philo)
	{
		pthread_mutex_init(&global->philo[i].fork, NULL);
		global->philo[i].fork_left = &global->philo[i].fork;
		i++;
	}
	i = 0;
	while (i < global->nb_philo)
	{
		if (i == global->nb_philo - 1)
			global->philo[i].fork_right = &global->philo[0].fork;
		else
			global->philo[i].fork_right = &global->philo[i + 1].fork;
		global->philo[i].id = i + 1;
		i++;
	}
	pthread_mutex_init(&global->dead_check, NULL);
	return (ft_init_philo(global));
}

int	init(t_global *global, int argc, char **argv)
{
	global->nb_philo = atoi(argv[1]);
	global->t_death = atoi(argv[2]);
	global->t_eat = atoi(argv[3]);
	global->t_sleep = atoi(argv[4]);
	global->stop_thread = 0;
	if (argc == 6)
		global->nb_eat = atoi(argv[5]);
	else
		global->nb_eat = -1;
	global->philo = malloc(sizeof(t_philo) * atoi(argv[1]));
	if (!global->philo)
		return (1);
	global->thrds = malloc(sizeof(pthread_t) * atoi(argv[1]));
	if (!global->thrds)
		return (1);
	return (init_mutex(global));
}
