/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:40:21 by akurochk          #+#    #+#             */
/*   Updated: 2023/10/18 11:07:57 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	ck_end(int *c_pid, siginfo_t *info, char c)
{
	if (c == '\0')
	{
		ft_printf("\n");
		*c_pid = 0;
		kill(info->si_pid, SIGUSR2);
	}
}

static void	receive_message(int sig, siginfo_t *info, void *skip)
{
	static int				bit = -1;
	static unsigned char	c;
	static int				c_pid;

	(void)skip;
	if (!c_pid || c_pid == 0)
		c_pid = info->si_pid;
	if (c_pid == info->si_pid)
	{
		if (bit < 0)
			bit = 7;
		if (sig == SIGUSR1)
			c |= (1 << bit);
		bit--;
		if (bit < 0)
		{
			write(1, &c, 1);
			ck_end(&c_pid, info, c);
			c = 0;
		}
	}
	else
		kill(info->si_pid, SIGUSR1);
}

static void	signal_processing(void)
{
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(sa));
	sa.sa_sigaction = &receive_message;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("\033[1;31mError: SIGUSR1\033[1;0m\n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("\033[1;31mError: SIGUSR2\033[1;0m\n");
}

int	main(int ac, char **av)
{
	int		pid;

	(void)av;
	if (ac != 1)
	{
		ft_printf("\033[1;31mError: server no needs arguments\033[1;0m\n");
		ft_printf("\033[1;31mTry: ./server_bonus\033[1;0m\n");
		return (1);
	}
	pid = getpid();
	ft_printf("\033[1;32mPID: %d\033[1;0m\n", pid);
	ft_printf("\033[1;32mServer is ready.\033[1;0m\n");
	while (1)
		signal_processing();
	return (0);
}
