/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:59:52 by akurochk          #+#    #+#             */
/*   Updated: 2024/04/03 14:29:08 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	activate_threads(t_philo *ph, pthread_mutex_t *m_f, int nb_ph)
{
	int			i;
	pthread_t	reaper;

	i = -1;
	if (pthread_create(&reaper, NULL, &monitor, ph))
		return (free_all("Error: create thread reaper", ph->data, m_f));
	while (++i < nb_ph)
		if (pthread_create(&ph[i].thread, NULL, &routine, &ph[i]))
			return (free_all("Error: create threads phils", ph->data, m_f));
	i = -1;
	if (pthread_join(reaper, NULL))
		return (free_all("Error: join thread reaper", ph->data, m_f));
	while (++i < nb_ph)
		if (pthread_join(ph[i].thread, NULL))
			return (free_all("Error: join threads phils", ph->data, m_f));
	return (0);
}
