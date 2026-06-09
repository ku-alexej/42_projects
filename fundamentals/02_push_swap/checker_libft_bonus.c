/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_libft_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:16:04 by akurochk          #+#    #+#             */
/*   Updated: 2023/11/29 17:00:47 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

// Modified version
char	*ft_strjoin_with_space(char const *s1, char const *s2, int space)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	if (!s1 || !s2)
		return (0);
	res = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	if (!res)
		return (0);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	if (space)
		res[i] = ' ';
	res[i + 1] = 0;
	free((void *)s1);
	return (res);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// Modified version
int	ft_atoi_ck_int(const char *s, char **numbs, int *tab)
{
	int		i;
	int		sign;
	size_t	value;

	i = 0;
	value = 0;
	sign = 1;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	if (s[i] == '+' || s[i] == '-')
		if (s[i++] == '-')
			sign *= -1;
	while (ft_isdigit(s[i]))
	{
		value = value * 10 + s[i] - '0';
		i++;
		if ((long)value * sign < INT_MIN || (long)value * sign > INT_MAX)
		{
			free_numbs(numbs);
			free(tab);
			error_exit();
		}
	}
	return ((int)value * sign);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}
