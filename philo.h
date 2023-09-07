/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:10:07 by ealves            #+#    #+#             */
/*   Updated: 2023/09/07 12:48:16 by ealves           ###   ########.fr       */
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
	int				id;
	pthread_t		t_id;
	long int		last_eat;
	int				state;
	struct s_global	*global;
}	t_philo;

typedef struct s_global
{
	t_philo			*philo;
	int				nb_philo;
	unsigned int	t_death;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	unsigned int	nb_eat;
	pthread_mutex_t	print;
	pthread_mutex_t	dead;
	pthread_mutex_t	eat;
	pthread_mutex_t	*all_fork;
}	t_global;

//////////main.c///////////
int			check_arg(int argc, char **argv);

//////////utils.c///////////
int			ft_is_num(char *str);
int			ft_atoi(char *str);
// void		*ft_memset(void *s, int c, size_t n);
void		print_msg(t_philo *philo, char *msg);

//////////init.c///////////

long long	timestamp(void);
void		ft_usleep(long int time);
int			init(t_global *global, int argc, char **argv);

//////////algo.c///////////
void	ft_sleep(t_philo *philo);
void	ft_eat(t_philo *philo);
void	ft_fork(t_philo *philo);
void	*p_routine(void *philo);

#endif
