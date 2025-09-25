/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:50:04 by akurochk          #+#    #+#             */
/*   Updated: 2023/11/16 12:50:04 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_rank(t_list *ptr, int size)
{
	int			i;
	t_scroll	v;

	i = 0;
	while (++i <= ((size + 1) / 2))
	{
		v.ptr = ptr;
		while (v.ptr->rank)
			v.ptr = v.ptr->next;
		v.ptr_min = v.ptr;
		v.ptr_max = v.ptr;
		while (1)
		{
			if (!v.ptr->rank && v.ptr->num <= v.ptr_min->num)
				v.ptr_min = v.ptr;
			else if (!v.ptr->rank && v.ptr->num >= v.ptr_max->num)
				v.ptr_max = v.ptr;
			if (v.ptr->next == ptr)
				break ;
			v.ptr = v.ptr->next;
		}
		v.ptr_min->rank = i;
		v.ptr_max->rank = (size + 1 - i);
	}
}

int	min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	set_extremes(t_list *ptr, size_t *min, size_t *max)
{
	t_list	*n;

	n = ptr;
	*min = n->rank;
	*max = n->rank;
	while (1)
	{
		if (n->rank < *min)
			*min = n->rank;
		if (n->rank > *max)
			*max = n->rank;
		n = n->next;
		if (n == ptr)
			break ;
	}
}
