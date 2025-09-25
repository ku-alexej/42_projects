/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:40:43 by akurochk          #+#    #+#             */
/*   Updated: 2023/10/18 11:07:49 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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

static void	check_answer(int sig)
{
	if (sig == SIGUSR2)
		ft_printf("\033[1;32mMessage received\033[1;0m\n");
	else if (sig == SIGUSR1)
	{
		ft_printf("\033[1;93mServer is busy!\033[1;0m\n");
		exit(1);
	}
}

static void	signal_processing(void)
{
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(sa));
	sa.sa_handler = &check_answer;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("\033[1;31mError: SIGUSR1\033[1;0m\n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("\033[1;31mError: SIGUSR2\033[1;0m\n");
}

int	main(int ac, char **av)
{
	int		s_pid;

	if (ac != 3)
	{
		ft_printf("\033[1;31mError: wrong arguments\033[1;0m\n");
		ft_printf("\033[1;31mTry: ./client_bonus <PID> <MESSAGE>\033[1;0m\n");
		return (1);
	}
	s_pid = ft_atoi(av[1]);
	ft_printf("\033[1;34mSending message...\033[1;0m\n");
	signal_processing();
	send_message(s_pid, av[2]);
	return (0);
}
