/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:59:42 by ealves            #+#    #+#             */
/*   Updated: 2023/09/14 18:57:31 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// number_of_philosophers + time_to_die + time_to_eat + time_to_sleep

int	check_arg(int argc, char **argv)
{
	int	i;
	int	j;

	j = 1;
	if (argc < 5 || argc > 6)
	{
		printf("Error : wrong number of arguments\n");
		return (1);
	}
	while (j < argc)
	{
		i = 0;
		while (argv[j][i])
		{
			if (!ft_is_num(&argv[j][i]))
			{
				printf("Error : non-numerical arguments\n");
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_global	global;
	int			i;

	if (check_arg(argc, argv))
		return (1);
	if (ft_atoi(argv[1]) == 0 || ft_atoi(argv[1]) > 200)
	{
		printf("Error : wrong number of philosopher\n");
		return (1);
	}
	init(&global, argc, argv);
	i = 0;
	while (i < global.nb_philo)
	{
		global.philo[i].global = &global;
		pthread_create(&global.philo[i].t_id,
			NULL, &p_routine, &global.philo[i]);
		i++;
	}
	while (1)
		i++;
	return (0);
}
