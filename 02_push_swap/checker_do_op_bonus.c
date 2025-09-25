/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_do_op_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:49:38 by akurochk          #+#    #+#             */
/*   Updated: 2023/11/16 12:49:38 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	s_comp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	op_r(t_list **head, size_t size, int is_rrx)
{
	if (size < 2)
		return (0);
	if (is_rrx)
		*head = (*head)->prev;
	else
		*head = (*head)->next;
	return (1);
}

int	op_s(t_list **head, size_t size)
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

int	op_p(t_list **head1, size_t *size1, t_list **head2, size_t *size2)
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
