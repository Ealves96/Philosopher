/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:59:42 by ealves            #+#    #+#             */
/*   Updated: 2023/10/04 19:34:15 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// number_of_philosophers + time_to_die + time_to_eat + time_to_sleep
static void	freeall(t_global *global)
{
	unsigned int	i;

	i = -1;
	while (++i < global->nb_philo)
		pthread_mutex_destroy(&global->philo[i].fork);
	free(global->philo);
	free(global->thrds);
	pthread_mutex_destroy(&global->dead_check);
	free(global);
}

static void	ft_thrd_join(t_global *global)
{
	unsigned int	i;

	i = 0;
	while (i < global->nb_philo)
	{
		pthread_join(global->thrds[i], NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_global		*global;
	unsigned int	i;
	int				stop;

	stop = 0;
	global = malloc(sizeof(*global));
	if (!global)
		return (1);
	if (ft_check_arg(argc, argv))
		return (1);
	init(global, argc, argv);
	i = -1;
	while (++i < global->nb_philo)
	{
		global->philo[i].global = global;
		pthread_create(&global->thrds[i],
			NULL, &p_routine, &global->philo[i]);
	}
	while (stop == 0)
	{
		pthread_mutex_lock(&global->dead_check);
		stop = (check_death(global) || !check_nb_eat(global));
		pthread_mutex_unlock(&global->dead_check);
	}
	return (ft_thrd_join(global), freeall(global), 0);
}
