/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:50:21 by akurochk          #+#    #+#             */
/*   Updated: 2023/11/16 12:50:21 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	first_sort_loop(t_stk *stack, int need_rb, size_t x, size_t y)
{
	if (stack->a->rank <= (stack->size_a + stack->size_b - x))
	{
		if (need_rb)
		{
			do_op ("rb", stack);
			need_rb = 0;
		}
		do_op("pb", stack);
		if ((stack->size_b > 1) && (stack->size_a > 3)
			&& (stack->b->rank <= (stack->size_a + stack->size_b - x - y)))
			need_rb = 1;
	}
	else
	{
		if (need_rb)
			do_op ("rr", stack);
		else
			do_op("ra", stack);
		need_rb = 0;
	}
	return (need_rb);
}

static int	first_sort(t_stk *stack, size_t parts)
{
	size_t	x;
	size_t	y;
	int		need_rb;
	int		sorted;

	sorted = 0;
	need_rb = 0;
	y = (stack->size_a + 1) / parts;
	if (stack->size_a < 16)
		y = (stack->size_a + 1) / 3;
	x = stack->size_a - (2 * y);
	while (stack->size_a > 3 && stack->size_a >= x + 1 && !sorted)
	{
		need_rb = first_sort_loop(stack, need_rb, x, y);
		sorted = is_sorted(stack->a);
	}
	if (need_rb)
		do_op ("rb", stack);
	return (sorted);
}

static void	second_sort(t_stk *stack)
{
	size_t	min;
	size_t	max;

	set_extremes(stack->a, &min, &max);
	if (stack->a->rank == max)
		do_op("ra", stack);
	else if (stack->a->next->rank == max)
		do_op("rra", stack);
	if (stack->a->next->rank == min)
		do_op("sa", stack);
}

static void	final_sort(t_stk *stack)
{
	int	sens;

	sens = (stack->a->rank > (stack->size_a / 2));
	while (stack->a->rank != 1)
	{
		if (sens)
			do_op("ra", stack);
		else
			do_op("rra", stack);
	}
}

int	main(int ac, char **av)
{
	t_stk	stack;
	size_t	parts;
	int		sorted;

	if (ac == 1)
		return (EXIT_SUCCESS);
	ck_and_parse(ac, av, &stack);
	add_rank(stack.a, stack.size_a);
	parts = 11;
	sorted = 0;
	while (stack.size_a > 3)
	{
		if (parts < 3 || stack.size_a < 13)
			parts = 3;
		sorted = first_sort(&stack, parts--);
	}
	if (!sorted)
		second_sort(&stack);
	third_sort(&stack);
	final_sort(&stack);
	free_stack(stack.a);
	return (EXIT_SUCCESS);
}
