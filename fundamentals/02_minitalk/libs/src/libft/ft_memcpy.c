/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:23:31 by akurochk          #+#    #+#             */
/*   Updated: 2023/09/22 14:19:41 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ucdest;
	unsigned char	*ucsrc;

	if (!dest && !src)
		return (NULL);
	ucdest = (unsigned char *)dest;
	ucsrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		ucdest[i] = ucsrc[i];
		i++;
	}
	return (dest);
}
