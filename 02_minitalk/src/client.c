/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:40:43 by akurochk          #+#    #+#             */
/*   Updated: 2023/10/13 16:56:53 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sent_char(int s_pid, unsigned char c)
{
	int				i;

	i = 8;
	while (i--)
	{
		if (c & 0b10000000)
			kill(s_pid, SIGUSR1);
		else
			kill(s_pid, SIGUSR2);
		usleep(120);
		c <<= 1;
	}
}

static void	send_message(int s_pid, char *msg)
{
	unsigned char	c;

	while (*msg)
	{
		c = *msg;
		sent_char(s_pid, c);
		msg++;
	}
	sent_char(s_pid, '\0');
}

int	main(int ac, char **av)
{
	int		s_pid;

	if (ac != 3)
	{
		ft_printf("\033[1;31mError: wrong arguments\033[1;0m\n");
		ft_printf("\033[1;31mTry: ./client <PID> <MESSAGE>\033[1;0m\n");
		return (1);
	}
	s_pid = ft_atoi(av[1]);
	ft_printf("\033[1;34mSending message...\033[1;0m\n");
	send_message(s_pid, av[2]);
	return (0);
}
