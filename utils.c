/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:59:47 by ealves            #+#    #+#             */
/*   Updated: 2023/10/04 18:46:58 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_gettimeofday(void)
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

int	ft_is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9'))
			return (0);
		i++;
	}
	return (1);
}

void	print_msg(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->global->dead_check);
	printf("%lld %d %s\n", timestamp(), philo->id, msg);
	pthread_mutex_unlock(&philo->global->dead_check);
}

int	ft_atoi(char *str)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			count++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		j = j * 10 + (str[i] - '0');
		i++;
	}
	if (count % 2 == 1)
		return (-j);
	return (j);
}
