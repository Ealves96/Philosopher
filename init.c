/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:49:32 by ealves            #+#    #+#             */
/*   Updated: 2023/09/07 12:39:54 by ealves           ###   ########.fr       */
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

int	init(t_global *global, int argc, char **argv)
{
	int	i;

	i = 0;
	global->nb_philo = atoi(argv[1]);
	global->t_death = atoi(argv[2]);
	global->t_eat = atoi(argv[3]);
	global->t_sleep = atoi(argv[4]);
	if (argc == 6)
		global->nb_eat = atoi(argv[5]);
	global->all_fork = malloc(sizeof(pthread_mutex_t) * global->nb_philo);
	if (!global->all_fork)
		return (1);
	global->philo = malloc(sizeof(t_philo) * atoi(argv[1]) + 1);
	if (!global->philo)
		return (1);
	while (i < global->nb_philo)
	{
		pthread_mutex_init(&global->all_fork[i], NULL);
		global->philo[i].id = i;
		i++;
	}
	pthread_mutex_init(&global->print, NULL);
	pthread_mutex_init(&global->dead, NULL);
	pthread_mutex_init(&global->eat, NULL);
	return (0);
}