/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:59:35 by akurochk          #+#    #+#             */
/*   Updated: 2024/03/28 11:55:14 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data			data;
	t_philo			*ph;
	pthread_mutex_t	*m_f;

	if (!is_arg_ok(ac, av))
		return (EXIT_FAILURE);
	init_data(&data, ac, av);
	if (data.must_eat == 0)
		return (EXIT_SUCCESS);
	m_f = init_forks(data.nb_ph);
	if (m_f == NULL)
		return (printf("Error: can't init forks.\n"), EXIT_FAILURE);
	ph = init_philos(&data, m_f);
	if (ph == NULL)
	{
		free (m_f);
		return (printf("Error: can't init philos.\n"), EXIT_FAILURE);
	}
	if (activate_threads(ph, m_f, data.nb_ph) == 1)
		return (EXIT_FAILURE);
	return (free_all(NULL, &data, m_f), EXIT_SUCCESS);
}
