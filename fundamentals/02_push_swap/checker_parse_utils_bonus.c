/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_parse_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:29:58 by akurochk          #+#    #+#             */
/*   Updated: 2023/11/28 14:29:58 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	error_exit(void)
{
	ft_putstr_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	ck_empty_str(char *arg, char *s)
{
	int	i;

	i = 0;
	if (!arg[i])
	{
		free(s);
		error_exit();
	}
	while (arg[i] == ' ' || (arg[i] >= 9 && arg[i] <= 13)
		|| arg[i] == '+' || arg[i] == '-')
		i++;
	if (!arg[i])
	{
		free(s);
		error_exit();
	}
}

size_t	count_numbs(char **numbs)
{
	size_t	i;

	i = 0;
	while (numbs[i])
		i++;
	return (i);
}

void	free_numbs(char **numbs)
{
	int	i;

	i = 0;
	if (!numbs)
		return ;
	while (numbs[i])
	{	
		free(numbs[i]);
		i++;
	}
	free(numbs);
}

void	prepare_stack(t_stk *stack, int *tab, int len)
{
	stack->a = NULL;
	stack->size_a = len;
	stack->b = NULL;
	stack->size_b = 0;
	while (len)
		fill_stack(tab[--len], &(stack->a), tab);
	free(tab);
}
