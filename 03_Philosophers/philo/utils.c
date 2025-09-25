/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:59:45 by akurochk          #+#    #+#             */
/*   Updated: 2024/03/26 18:03:27 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	status(t_philo *ph, char *status, int mode)
{
	int	timestamp;

	timestamp = get_timestamp() - ph->data->start_time;
	if (mode == 1)
	{
		printf("%d %d %s\n", timestamp, ph->id, status);
		return ;
	}
	pthread_mutex_lock(&ph->data->m_status);
	if (!is_silence(ph->data))
		printf("%d %d %s\n", timestamp, ph->id, status);
	pthread_mutex_unlock(&ph->data->m_status);
}

int	is_silence(t_data *data)
{
	pthread_mutex_lock(&data->m_silence);
	if (data->silence == 1)
	{
		pthread_mutex_unlock(&data->m_silence);
		return (1);
	}
	pthread_mutex_unlock(&data->m_silence);
	return (0);
}

int	free_all(char *msg, t_data *data, pthread_mutex_t *m_f)
{
	int	i;

	i = -1;
	if (msg != NULL)
		printf("%s\n", msg);
	pthread_mutex_destroy(&data->m_status);
	pthread_mutex_destroy(&data->m_eat);
	pthread_mutex_destroy(&data->m_silence);
	i = 0;
	while (i < data->nb_ph)
	{
		pthread_mutex_destroy(&m_f[i]);
		i++;
	}
	free(data->ph);
	free(m_f);
	return (1);
}
