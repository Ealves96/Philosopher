/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:10:07 by ealves            #+#    #+#             */
/*   Updated: 2023/10/02 22:47:02 by elie             ###   ########.fr       */
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
	int				status;
	pthread_mutex_t	fork;
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	*fork_left;
	struct s_global	*global;
}	t_philo;

typedef struct s_global
{
	t_philo			*philo;
	int				nb_philo; //arg1
	unsigned int	t_death; // arg2
	unsigned int	t_eat; //arg3
	unsigned int	t_sleep; //arg4
	unsigned int	nb_eat; //arg5
	pthread_mutex_t	print;
	pthread_mutex_t	dead_check;
	unsigned int	dead;
}	t_global;

//////////main.c///////////
void		freeall(t_global *global);
int			check_arg(int argc, char **argv);

//////////utils.c///////////
int			ft_is_num(char *str);
int			ft_atoi(char *str);
void		print_msg(t_philo *philo, char *msg);

//////////init.c///////////

long long	timestamp(void);
void		ft_usleep(long int time, t_global *global);
int			init_fork(t_global *global);
int			init(t_global *global, int argc, char **argv);

//////////algo.c///////////
void	ft_sleep(t_philo *philo);
void	ft_eat(t_philo *philo);
int		ft_recup_fork(t_philo *philo);
void	*p_routine(void *philo);

//////////check_philo.c////
int 	is_death(t_philo *philo);

#endif
