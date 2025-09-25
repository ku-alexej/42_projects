/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:37:11 by akurochk          #+#    #+#             */
/*   Updated: 2023/05/04 10:40:10 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ucs;
	size_t			i;

	i = 0;
	ucs = (unsigned char *)s;
	while (i < n)
	{
		if (ucs[i] == (unsigned char)c)
			return (ucs + i);
		i++;
	}
	return (NULL);
}
