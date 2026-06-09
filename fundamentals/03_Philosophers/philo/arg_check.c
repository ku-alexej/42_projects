/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:51:20 by akurochk          #+#    #+#             */
/*   Updated: 2024/03/26 18:07:12 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	ft_atol(char *num)
{
	long	result;
	long	i;

	result = 0;
	i = 0;
	while (num[i])
	{
		result = result * 10 + num[i] - 48;
		i++;
	}
	return (result);
}

static int	is_numeric(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
			{
				printf("Error: to run the program ");
				printf("use positive numbers as arguments.\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	is_big_or_small(char **av)
{
	int		i;
	long	n[5];

	i = 1;
	while (av[i])
	{
		n[i - 1] = ft_atol(av[i]);
		i++;
	}
	if (av[5] == NULL)
		n[4] = -1;
	if (n[0] == 0 || n[1] == 0 || n[2] == 0 || n[3] == 0)
	{
		printf("Error: number_of_philosophers and time_to_... ");
		printf("must be greater than zero.\n");
		return (1);
	}
	if ((n[0] > INT_MAX || n[1] > INT_MAX || n[2] > INT_MAX || n[3] > INT_MAX)
		|| (n[4] != -1 && n[4] > INT_MAX))
	{
		printf("Error: some arguments are too big.\n");
		return (1);
	}
	return (0);
}

static void	msg(void)
{
	printf("Try: ");
	printf("\033[0;31m./philo ");
	printf("\033[0;32mnumber_of_philosophers \033[0m");
	printf("\033[0;33mtime_to_die \033[0m");
	printf("\033[0;34mtime_to_eat \033[0m");
	printf("\033[0;35mtime_to_sleep \033[0m");
	printf("\033[0;36m[number_of_times_each_philosopher_must_eat]\033[0m");
	printf("\n");
}

int	is_arg_ok(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (msg(), 0);
	if (is_numeric(av) == 0)
		return (0);
	if (is_big_or_small(av) == 1)
		return (0);
	return (1);
}
