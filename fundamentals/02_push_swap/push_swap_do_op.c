/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_do_op.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:49:38 by akurochk          #+#    #+#             */
/*   Updated: 2023/11/16 12:49:38 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	s_comp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	op_r(t_list **head, size_t size, int is_rrx)
{
	if (size < 2)
		return (0);
	if (is_rrx)
		*head = (*head)->prev;
	else
		*head = (*head)->next;
	return (1);
}

static int	op_s(t_list **head, size_t size)
{
	int		buff_n;
	size_t	buff_r;

	if (size < 2)
		return (0);
	if (size > 2)
	{
		buff_n = (*head)->next->num;
		buff_r = (*head)->next->rank;
		(*head)->next->num = (*head)->num;
		(*head)->next->rank = (*head)->rank;
		(*head)->num = buff_n;
		(*head)->rank = buff_r;
		return (1);
	}
	*head = (*head)->next;
	return (1);
}

static int	op_p(t_list **head1, size_t *size1, t_list **head2, size_t *size2)
{
	t_list	*buff;

	buff = (*head1)->next;
	buff->prev = (*head1)->prev;
	buff->prev->next = buff;
	if (!*size2)
	{
		(*head1)->prev = *head1;
		(*head1)->next = *head1;
	}
	else
	{
		(*head1)->prev = (*head2)->prev;
		(*head1)->next = *head2;
		(*head2)->prev = *head1;
		(*head1)->prev->next = *head1;
	}
	*head2 = *head1;
	*head1 = buff;
	(*size1)--;
	if (!*size1)
		*head1 = NULL;
	(*size2)++;
	return (1);
}

void	do_op(char *mvt, t_stk *stack)
{
	int	ok;

	ok = 0;
	if (!s_comp(mvt, "ra") || !s_comp(mvt, "rr"))
		ok = op_r(&stack->a, stack->size_a, 0);
	if (!s_comp(mvt, "rb") || !s_comp(mvt, "rr"))
		ok = op_r(&stack->b, stack->size_b, 0);
	if (!s_comp(mvt, "rra") || !s_comp(mvt, "rrr"))
		ok = op_r(&stack->a, stack->size_a, 1);
	if (!s_comp(mvt, "rrb") || !s_comp(mvt, "rrr"))
		ok = op_r(&stack->b, stack->size_b, 1);
	if (!s_comp(mvt, "sa") || !s_comp(mvt, "ss"))
		ok = op_s(&stack->a, stack->size_a);
	if (!s_comp(mvt, "sb") || !s_comp(mvt, "ss"))
		ok = op_s(&stack->b, stack->size_b);
	if ((!s_comp(mvt, "pa")) && (stack->b))
		ok = op_p(&stack->b, &stack->size_b, &stack->a, &stack->size_a);
	if ((!s_comp(mvt, "pb")) && (stack->a))
		ok = op_p(&stack->a, &stack->size_a, &stack->b, &stack->size_b);
	if (ok)
		ft_putstr_fd(mvt, STDOUT_FILENO);
}
