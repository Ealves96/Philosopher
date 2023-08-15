/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:10:07 by ealves            #+#    #+#             */
/*   Updated: 2023/08/15 19:12:42 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{

}	t_philo;

typedef struct s_global
{
	t_philo	*philo;
	int		nb_philo;
	int		death;
	int		eat;
	int		sleep;
	int		nb_eat;
}	t_global;

//////////main.c///////////
int		check_arg(int argc, char **argv);

//////////utils.c///////////
int		ft_is_num(char *str);
int		ft_atoi(char *str);
void	*ft_memset(void *s, int c, size_t n);

#endif
