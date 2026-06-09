/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:27:54 by akurochk          #+#    #+#             */
/*   Updated: 2023/09/22 14:19:55 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*n;

	if (!lst)
		return ;
	while (*lst)
	{
		n = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = n;
	}
	*lst = NULL;
}
