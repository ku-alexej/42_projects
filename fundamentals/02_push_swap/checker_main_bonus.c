/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:48:44 by akurochk          #+#    #+#             */
/*   Updated: 2023/11/16 12:48:44 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	check_and_do_op(char *mvt, t_stk *stack)
{
	if (s_comp(mvt, "ra\n") && s_comp(mvt, "rb\n") && s_comp(mvt, "rr\n")
		&& s_comp(mvt, "rra\n") && s_comp(mvt, "rrb\n") && s_comp(mvt, "rrr\n")
		&& s_comp(mvt, "sa\n") && s_comp(mvt, "sb\n") && s_comp(mvt, "ss\n")
		&& s_comp(mvt, "pa\n") && s_comp(mvt, "pb\n"))
		return (0);
	if (!s_comp(mvt, "ra\n") || !s_comp(mvt, "rr\n"))
		op_r(&stack->a, stack->size_a, 0);
	if (!s_comp(mvt, "rb\n") || !s_comp(mvt, "rr\n"))
		op_r(&stack->b, stack->size_b, 0);
	if (!s_comp(mvt, "rra\n") || !s_comp(mvt, "rrr\n"))
		op_r(&stack->a, stack->size_a, 1);
	if (!s_comp(mvt, "rrb\n") || !s_comp(mvt, "rrr\n"))
		op_r(&stack->b, stack->size_b, 1);
	if (!s_comp(mvt, "sa\n") || !s_comp(mvt, "ss\n"))
		op_s(&stack->a, stack->size_a);
	if (!s_comp(mvt, "sb\n") || !s_comp(mvt, "ss\n"))
		op_s(&stack->b, stack->size_b);
	if ((!s_comp(mvt, "pa\n")) && (stack->b))
		op_p(&stack->b, &stack->size_b, &stack->a, &stack->size_a);
	if ((!s_comp(mvt, "pb\n")) && (stack->a))
		op_p(&stack->a, &stack->size_a, &stack->b, &stack->size_b);
	return (1);
}

static int	read_mvt(t_stk *stack)
{
	int		ok;
	char	*mvt;

	ok = 1;
	while (ok)
	{
		mvt = get_next_line(STDIN_FILENO);
		if (!mvt)
			break ;
		if (!s_comp(mvt, "\n"))
		{
			free(mvt);
			break ;
		}
		ok = check_and_do_op(mvt, stack);
		free(mvt);
		mvt = 0;
	}
	get_next_line(-1);
	return (ok);
}

int	main(int ac, char **av)
{
	t_stk	stack;
	int		ok;

	if (ac == 1)
		return (EXIT_SUCCESS);
	ck_and_parse(ac, av, &stack);
	ok = read_mvt(&stack);
	if (ok)
	{
		if (is_sorted(stack.a) && !stack.size_b)
			ft_putstr_fd("OK", STDOUT_FILENO);
		else
			ft_putstr_fd("KO", STDOUT_FILENO);
	}
	else
		ft_putstr_fd("Error", STDERR_FILENO);
	free_stack(stack.a);
	free_stack(stack.b);
	return (EXIT_SUCCESS);
}
