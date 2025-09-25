/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 09:26:09 by akurochk          #+#    #+#             */
/*   Updated: 2023/12/19 16:56:37 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_get_val(const char c, const char *base)
{
	int	val;

	val = 0;
	while (base[val] != '\0')
	{
		if (c == base[val])
			break ;
		val++;
	}
	if (base[val] == '\0')
		return (-1);
	return (val);
}

unsigned int	ft_atoi_hex(const char *str)
{
	unsigned int	res;
	char			*base;

	res = 0;
	base = "0123456789ABCDEF";
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (ft_strncmp(str, "0x", 2) == 0)
		str += 2;
	while (*str != '\0')
	{
		if (ft_get_val(ft_toupper(*str), base) >= 0)
			res = (res * 16) + ft_get_val(ft_toupper(*str), base);
		else
			break ;
		str++;
	}
	return (res);
}
