/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:00:07 by akurochk          #+#    #+#             */
/*   Updated: 2024/03/26 17:18:29 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_atoi(char *num)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (num[i])
	{
		result = result * 10 + num[i] - 48;
		i++;
	}
	return (result);
}

void	init_data(t_data *data, int ac, char **av)
{
	data->nb_ph = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->must_eat = -1;
	if (ac == 6)
		data->must_eat = ft_atoi(av[5]);
	data->silence = 0;
	data->start_time = get_timestamp();
	pthread_mutex_init(&data->m_status, NULL);
	pthread_mutex_init(&data->m_eat, NULL);
	pthread_mutex_init(&data->m_silence, NULL);
}

pthread_mutex_t	*init_forks(int ph_num)
{
	int				i;
	pthread_mutex_t	*m_f;

	i = -1;
	m_f = malloc((sizeof(pthread_mutex_t) * ph_num));
	if (m_f == NULL)
		return (NULL);
	while (++i < ph_num)
		pthread_mutex_init(&m_f[i], NULL);
	return (m_f);
}

t_philo	*init_philos(t_data *data, pthread_mutex_t *m_f)
{
	int		i;
	int		j;
	t_philo	*ph;

	i = -1;
	ph = malloc(sizeof(t_philo) * data->nb_ph);
	if (ph == NULL)
		return (NULL);
	while (++i < data->nb_ph)
	{
		j = (data->nb_ph + i - 1) % data->nb_ph;
		ph[i].id = i + 1;
		ph[i].data = data;
		ph[i].meals = 0;
		ph[i].start_meal = get_timestamp();
		ph[i].m_l = &m_f[i];
		ph[i].m_r = &m_f[j];
	}
	data->ph = ph;
	return (ph);
}
