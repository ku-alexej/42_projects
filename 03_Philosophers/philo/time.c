/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:59:49 by akurochk          #+#    #+#             */
/*   Updated: 2024/03/26 16:37:05 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	timer(int time_in_ms)
{
	int	start;

	start = get_timestamp();
	while ((get_timestamp() - start) < time_in_ms)
		usleep(1000);
}

int	get_timestamp(void)
{
	struct timeval	timeval;

	if (gettimeofday(&timeval, NULL))
		return (0);
	return ((timeval.tv_sec * 1000) + (timeval.tv_usec / 1000));
}
