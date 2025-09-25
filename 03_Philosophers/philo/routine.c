/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:25:56 by akurochk          #+#    #+#             */
/*   Updated: 2024/04/03 15:05:03 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	lonely_death(t_philo *ph)
{
	pthread_mutex_lock(ph->m_l);
	status(ph, "has taken a fork", 0);
	timer(ph->data->time_to_die + 5);
	pthread_mutex_unlock(ph->m_l);
}

static void	routine_eat(t_philo *ph)
{
	pthread_mutex_lock(ph->m_l);
	status(ph, "has taken a fork", 0);
	pthread_mutex_lock(ph->m_r);
	status(ph, "has taken a fork", 0);
	status(ph, "is eating", 0);
	pthread_mutex_lock(&ph->data->m_eat);
	ph->start_meal = get_timestamp();
	pthread_mutex_unlock(&ph->data->m_eat);
	if (is_silence(ph->data))
	{
		pthread_mutex_unlock(ph->m_r);
		pthread_mutex_unlock(ph->m_l);
		return ;
	}
	timer(ph->data->time_to_eat);
	pthread_mutex_lock(&ph->data->m_eat);
	ph->meals++;
	pthread_mutex_unlock(&ph->data->m_eat);
	pthread_mutex_unlock(ph->m_r);
	pthread_mutex_unlock(ph->m_l);
}

static void	routine_sleep(t_philo *ph)
{
	status(ph, "is sleeping", 0);
	timer(ph->data->time_to_sleep);
}

static void	routine_think(t_philo *ph)
{
	status(ph, "is thinking", 0);
	timer(1);
}

void	*routine(void *ptr)
{
	t_philo	*ph;

	ph = (t_philo *)ptr;
	if (ph->data->nb_ph == 1)
	{
		lonely_death(ph);
		return (ph);
	}
	if (ph->id % 2 != 0)
	{
		routine_think(ph);
		timer(ph->data->time_to_eat / 2);
	}
	while (!is_silence(ph->data))
	{
		routine_eat(ph);
		if (!is_silence(ph->data))
			routine_sleep(ph);
		if (!is_silence(ph->data))
			routine_think(ph);
	}
	return (ph);
}
