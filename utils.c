/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:59:47 by ealves            #+#    #+#             */
/*   Updated: 2023/09/07 12:45:53 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	print_msg(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->global->print);
	printf("timestamp : %lld id : %d msg : %s\n", timestamp(), philo->id, msg);
	pthread_mutex_unlock(&philo->global->print);
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

// void	*ft_memset(void *s, int c, size_t n)
// {
// 	size_t	i;
// 	char	*kol;

// 	i = 0;
// 	kol = (char *) s;
// 	while (i < n)
// 	{
// 		kol[i] = c;
// 		i++;
// 	}
// 	return (s);
// }
