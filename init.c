/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:49:32 by ealves            #+#    #+#             */
/*   Updated: 2023/10/03 20:40:16 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long long	ft_gettimeofday(void)
{
	struct timeval	time_v;

	gettimeofday(&time_v, NULL);
	return (((long long)(time_v.tv_sec)) * 1000
		+ ((long long)(time_v.tv_usec)) / 1000);
}

long long	timestamp(void)
{
	static long long	start = 0;

	if (start == 0)
		start = ft_gettimeofday();
	return (ft_gettimeofday() - start);
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
	pthread_mutex_init(&global->print, NULL);
	pthread_mutex_init(&global->dead_check, NULL);
	return (0);
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
	global->philo = malloc(sizeof(t_philo) * atoi(argv[1]) + 1);
	if (!global->philo)
		return (1);
	init_mutex(global);
	return (0);
}
