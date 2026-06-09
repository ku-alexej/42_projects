/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:49:58 by akurochk          #+#    #+#             */
/*   Updated: 2023/11/16 12:49:58 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(int num, t_list **ptr_a, int *tab)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
	{
		free(tab);
		free_stack(*ptr_a);
		exit(EXIT_FAILURE);
	}
	node->num = num;
	node->rank = 0;
	if (!(*ptr_a))
	{
		*ptr_a = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->next = *ptr_a;
		node->prev = (*ptr_a)->prev;
		(*ptr_a)->prev->next = node;
		(*ptr_a)->prev = node;
		*ptr_a = node;
	}
}

int	is_sorted(t_list *ptr)
{
	int		ok;
	t_list	*p;

	ok = 1;
	p = ptr;
	while (p->next != ptr && ok)
	{
		p = p->next;
		if (p->num < p->prev->num)
			ok = 0;
	}
	return (ok);
}

void	free_stack(t_list *ptr)
{
	t_list	*buf;

	if (ptr)
	{
		ptr->prev->next = NULL;
		while (ptr->next)
		{
			buf = ptr;
			ptr = ptr->next;
			free (buf);
		}
		free(ptr);
	}
}
