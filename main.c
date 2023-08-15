/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:59:42 by ealves            #+#    #+#             */
/*   Updated: 2023/08/15 19:19:40 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// number_of_philosophers + time_to_die + time_to_eat + time_to_sleep

int	init(t_global *global, int argc, char **argv)
{
	global->philo = malloc(sizeof(t_philo) * atoi(argv[1]) + 1);
	if (!global->philo)
		return (1);
	global->nb_philo = atoi(argv[1]);
	global->death = atoi(argv[2]);
	global->eat = atoi(argv[3]);
	global->sleep = atoi(argv[4]);
	if (argc == 6)
		global->nb_eat = atoi(argv[5]);
	return (0);
}

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

	if (check_arg(argc, argv))
		return (1);
	if (argv[1][0] == '0')
	{
		printf("Error : no philosopher\n");
		return (1);
	}
	init(&global, argc, argv);
	return (0);
}
