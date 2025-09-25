/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:59:59 by akurochk          #+#    #+#             */
/*   Updated: 2024/04/03 14:35:54 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_starving(t_philo *ph)
{
	pthread_mutex_lock(&ph->data->m_eat);
	if (get_timestamp() - ph->start_meal >= ph->data->time_to_die)
	{
		pthread_mutex_unlock(&ph->data->m_eat);
		return (1);
	}
	pthread_mutex_unlock(&ph->data->m_eat);
	return (0);
}

static int	dead_detected(t_philo *ph)
{
	int	i;

	i = -1;
	while (++i < ph[0].data->nb_ph)
	{
		if (is_starving(&ph[i]))
		{
			pthread_mutex_lock(&ph[0].data->m_silence);
			status(&ph[i], "died", 1);
			ph[0].data->silence = 1;
			pthread_mutex_unlock(&ph[0].data->m_silence);
			return (1);
		}
	}
	return (0);
}

static int	all_ate(t_philo *ph)
{
	int	i;
	int	ph_eaten;

	i = -1;
	ph_eaten = 0;
	if (ph[0].data->must_eat == -1)
		return (0);
	while (++i < ph[0].data->nb_ph)
	{
		pthread_mutex_lock(&ph[0].data->m_eat);
		if (ph[i].meals >= ph[0].data->must_eat)
			ph_eaten++;
		pthread_mutex_unlock(&ph[0].data->m_eat);
	}
	if (ph_eaten == ph[0].data->nb_ph)
	{
		pthread_mutex_lock(&ph[0].data->m_silence);
		ph[0].data->silence = 1;
		pthread_mutex_unlock(&ph[0].data->m_silence);
		return (1);
	}
	return (0);
}

void	*monitor(void *ptr)
{
	t_philo	*ph;

	ph = (t_philo *)ptr;
	while (1)
		if (dead_detected(ph) || all_ate(ph))
			break ;
	return (ph);
}
