/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:57:24 by akurochk          #+#    #+#             */
/*   Updated: 2023/12/15 19:17:46 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_gnl(const char *s, int c)
{
	if (c < 0)
		return (NULL);
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen_gnl(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static void	ft_bzero_gnl(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

void	*ft_calloc_gnl(size_t nmemb, size_t size)
{
	void	*res;

	if (!nmemb || !size || ((nmemb * size) / nmemb) != size)
		return (NULL);
	res = malloc(size * nmemb);
	if (!res)
		return (NULL);
	ft_bzero_gnl(res, size * nmemb);
	return (res);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!res)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		res[++j] = s1[i];
	i = -1;
	while (s2[++i])
		res[++j] = s2[i];
	res[++j] = 0;
	return (res);
}
