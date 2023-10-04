/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:35:31 by jralph            #+#    #+#             */
/*   Updated: 2023/10/04 19:34:51 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_check_arg2(int argc, char **argv)
{
	int	j;

	j = 0;
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[1]) > 200)
	{
		printf("Error : wrong number of philosopher\n");
		return (1);
	}
	while (++j < argc)
	{
		if (ft_atoi(argv[j]) <= 0)
			return (printf("Error : negative number find\n"), 1);
	}
	return (0);
}

int	ft_check_arg(int argc, char **argv)
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
	return (ft_check_arg2(argc, argv));
}
