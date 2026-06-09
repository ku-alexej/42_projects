/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:49:48 by akurochk          #+#    #+#             */
/*   Updated: 2023/11/16 12:49:48 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ck_arg(int j, char c, char **numbs, int *tab)
{
	if ((j == 0 && !ft_isdigit(c) && c != '-' && c != '+')
		|| (j > 0 && !ft_isdigit(c)))
	{
		free_numbs(numbs);
		free(tab);
		error_exit();
	}
}

static void	ck_duplicates(int *tab, int n, int len, char **numbs)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (tab[i] == n)
		{
			free_numbs(numbs);
			free(tab);
			error_exit();
		}
		i++;
	}
}

static void	ck_sort(int *tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (i > 0 && tab[i - 1] > tab[i])
			return ;
		i++;
	}
	free(tab);
	exit(EXIT_SUCCESS);
}

static int	*get_ints(size_t count, char **numbs)
{
	int	i;
	int	j;
	int	*tab;

	tab = malloc(sizeof(int) * (count));
	if (!tab)
	{
		free_numbs(numbs);
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (numbs[++i])
	{
		j = 0;
		while (numbs[i][j])
		{
			ck_arg(j, numbs[i][j], numbs, tab);
			j++;
		}
		tab[i] = ft_atoi_ck_int(numbs[i], numbs, tab);
		ck_duplicates(tab, tab[i], i, numbs);
	}
	free_numbs(numbs);
	ck_sort(tab, count);
	return (tab);
}

void	ck_and_parse(int ac, char **av, t_stk *stack)
{
	size_t	i;
	char	*s;
	char	**numbs;
	int		*tab;

	if (ac == 1)
		exit(EXIT_SUCCESS);
	i = 1;
	s = malloc(sizeof(char));
	if (!s)
		exit(EXIT_FAILURE);
	s[0] = 0;
	while (i < (size_t)ac)
	{
		ck_empty_str(av[i], s);
		s = ft_strjoin_space(s, av[i++]);
	}
	numbs = ft_split(s, ' ');
	free(s);
	if (numbs == NULL)
		exit(EXIT_FAILURE);
	i = count_numbs(numbs);
	tab = get_ints(i, numbs);
	prepare_stack(stack, tab, i);
}
