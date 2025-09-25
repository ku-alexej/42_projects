/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:27:48 by akurochk          #+#    #+#             */
/*   Updated: 2023/09/22 14:18:22 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ucdest;
	unsigned char	*ucsrc;

	if (!dest && !src)
		return (NULL);
	ucdest = (unsigned char *)dest;
	ucsrc = (unsigned char *)src;
	if (ucdest > ucsrc)
	{
		while (n--)
			ucdest[n] = ucsrc[n];
	}
	else
	{
		i = -1;
		while (++i < n)
			ucdest[i] = ucsrc[i];
	}
	return (dest);
}
