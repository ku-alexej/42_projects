/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:45:04 by akurochk          #+#    #+#             */
/*   Updated: 2023/05/10 15:56:23 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	i;
	size_t	l_len;

	if (!big && len == 0)
		return (NULL);
	if (!little[0])
		return ((char *)big);
	i = 0;
	l_len = ft_strlen(little);
	while (big[i] && i < len)
	{
		if (ft_strncmp(little, big + i, l_len) == 0 && i + l_len <= len)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
