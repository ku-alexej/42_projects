/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_third_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:49:52 by akurochk          #+#    #+#             */
/*   Updated: 2023/11/16 12:49:52 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	save_best(t_score *s, t_combo *c, t_combo *b)
{
	if (c->qty == s->qty[3])
	{
		b->nb_rrr = min(c->nb_rra, c->nb_rrb);
		if (c->nb_rra > c->nb_rrb)
			b->nb_rra = (c->nb_rra - c->nb_rrb);
		else
			b->nb_rrb = (c->nb_rrb - c->nb_rra);
	}
	else if (c->qty == s->qty[2])
	{
		b->nb_rr = min(c->nb_ra, c->nb_rb);
		if (c->nb_ra > c->nb_rb)
			b->nb_ra = (c->nb_ra - c->nb_rb);
		else
			b->nb_rb = (c->nb_rb - c->nb_ra);
	}
	else
	{
		b->nb_rra = (c->qty == s->qty[1]) * c->nb_rra;
		b->nb_rb = (c->qty == s->qty[1]) * c->nb_rb;
		b->nb_ra = (c->qty == s->qty[0]) * c->nb_ra;
		b->nb_rrb = (c->qty == s->qty[0]) * c->nb_rrb;
	}
}

static void	find_num_in_a(t_stk *stack, t_score *s, t_combo c)
{
	s->scroll_a = stack->a;
	s->i = 0;
	while (1)
	{
		if (s->scroll_a->rank < s->scroll_a->prev->rank)
		{
			if (c.num < s->scroll_a->rank)
				break ;
			if (c.num > s->scroll_a->prev->rank)
				break ;
		}
		else if (s->scroll_a->prev->rank < c.num && c.num < s->scroll_a->rank)
			break ;
		s->i++;
		s->scroll_a = s->scroll_a->next;
	}
}

static void	third_sort_loop(t_stk *stack, t_score *s, t_combo *c, t_combo *b)
{
	c->num = s->scroll_b->rank;
	c->nb_rb = (stack->size_b + s->i1) % stack->size_b;
	c->nb_rrb = ((stack->size_b - c->nb_rb) * (c->nb_rb != 0));
	find_num_in_a(stack, s, *c);
	c->nb_ra = s->i;
	c->nb_rra = stack->size_a - s->i;
	s->qty[0] = s->size_ab - c->num + (c->nb_ra + c->nb_rrb);
	s->qty[1] = s->size_ab - c->num + (c->nb_rra + c->nb_rb);
	s->qty[2] = s->size_ab - c->num + max(c->nb_rb, c->nb_ra);
	s->qty[3] = s->size_ab - c->num + max(c->nb_rrb, c->nb_rra);
	c->qty = min(min(min(s->qty[0], s->qty[1]), s->qty[2]), s->qty[3]);
	if ((c->qty < b->qty) || (c->qty == b->qty && c->num > b->num))
	{
		b->qty = c->qty;
		b->num = c->num;
		b->nb_ra = 0;
		b->nb_rra = 0;
		b->nb_rb = 0;
		b->nb_rrb = 0;
		b->nb_rr = 0;
		b->nb_rrr = 0;
		save_best(s, c, b);
	}
	s->i1++;
	s->scroll_b = s->scroll_b->next;
}

static void	use_best(t_stk *stack, t_combo b)
{
	while (b.nb_rr-- > 0)
		do_op("rr", stack);
	while (b.nb_rrr-- > 0)
		do_op("rrr", stack);
	while (b.nb_ra-- > 0)
		do_op("ra", stack);
	while (b.nb_rra-- > 0)
		do_op("rra", stack);
	while (b.nb_rb-- > 0)
		do_op("rb", stack);
	while (b.nb_rrb-- > 0)
		do_op("rrb", stack);
	do_op("pa", stack);
}

void	third_sort(t_stk *stack)
{
	t_score	score;
	t_combo	current;
	t_combo	best;

	while (stack->size_b > 0)
	{
		if (stack->size_a < stack->size_b)
			score.i = stack->size_a;
		else
			score.i = stack->size_b;
		score.i1 = -score.i / 2;
		score.i2 = score.i + score.i1;
		score.scroll_b = stack->b;
		score.i = -score.i1;
		while (score.i--)
			score.scroll_b = score.scroll_b->prev;
		best.qty = INT_MAX;
		best.num = 0;
		score.size_ab = stack->size_a + stack->size_b;
		while (score.i1 < score.i2)
			third_sort_loop(stack, &score, &current, &best);
		use_best(stack, best);
	}
}
