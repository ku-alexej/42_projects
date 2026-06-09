/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:21:01 by akurochk          #+#    #+#             */
/*   Updated: 2023/05/10 15:58:01 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_find_start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] && ft_is_in_set(s1[i], set))
		i++;
	return (i);
}

static int	ft_find_end(char const *s1, char const *set, int start)
{
	int	i;

	i = ft_strlen(s1) - 1;
	if (i == start)
		return (start - 1);
	while (start < i && s1[i] && ft_is_in_set(s1[i], set))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*res;

	if (!s1)
		return (NULL);
	start = ft_find_start(s1, set);
	end = ft_find_end(s1, set, start);
	res = (char *)malloc(end - start + 2);
	if (!res)
		return (NULL);
	i = start;
	while (i <= end)
	{
		res[i - start] = s1[i];
		i++;
	}
	res[i - start] = 0;
	return (res);
}
