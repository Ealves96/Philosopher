/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:10:07 by ealves            #+#    #+#             */
/*   Updated: 2023/10/03 21:04:27 by jralph           ###   ########.fr       */
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
	int				nb_eat;
	pthread_mutex_t	fork;
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	*fork_left;
	struct s_global	*global;
}	t_philo;

typedef struct s_global
{
	t_philo			*philo;
	unsigned int	nb_philo; //arg1
	unsigned int	t_death; // arg2
	unsigned int	t_eat; //arg3
	unsigned int	t_sleep; //arg4
	int				nb_eat; //arg5
	pthread_mutex_t	print;
	pthread_mutex_t	dead_check;
	unsigned int	stop_thread;
}	t_global;

//////////utils.c///////////
int			ft_is_num(char *str);
int			ft_atoi(char *str);
void		print_msg(t_philo *philo, char *msg);

//////////init.c///////////

long long	timestamp(void);
void		ft_usleep(long int time);
int			init(t_global *global, int argc, char **argv);

//////////algo.c///////////
void		ft_sleep(t_philo *philo);
void		ft_eat(t_philo *philo);
void		*p_routine(void *philo);

//////////check_philo.c////
int			check_stop(t_global *global);
int			check_death(t_global *global);
int			check_nb_eat(t_global *global);

///////////check_arg.c////////
int			ft_check_arg(int argc, char **argv);

////////eat.c////////
void		ft_eat(t_philo *philo);
int			ft_recup_fork(t_philo *philo);

#endif
