/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:50:23 by ealves            #+#    #+#             */
/*   Updated: 2023/10/02 22:22:32 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_death(t_philo *philo)
{
    int res;
    
    res = philo->global->t_eat - philo->last_eat;
    pthread_mutex_lock(&philo->global->dead_check);
    if (res <= 0) {
        pthread_mutex_unlock(&philo->global->dead_check);
        return (1);
    }
    pthread_mutex_unlock(&philo->global->dead_check);
    return (0);
}