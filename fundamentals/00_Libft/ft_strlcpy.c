/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:48:26 by akurochk          #+#    #+#             */
/*   Updated: 2023/05/05 17:01:49 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	s_len;

	i = -1;
	s_len = ft_strlen(src);
	if (s_len + 1 < size)
	{
		while (++i < s_len + 1)
			dst[i] = src[i];
	}
	else if (size > 0)
	{
		while (++i < size - 1)
			dst[i] = src[i];
		dst[i] = 0;
	}
	return (s_len);
}
