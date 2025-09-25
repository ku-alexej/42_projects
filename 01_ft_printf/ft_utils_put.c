/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:59:19 by akurochk          #+#    #+#             */
/*   Updated: 2023/06/13 10:44:27 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_char(char c)
{
	unsigned char	s;

	s = (unsigned char)c;
	return (write(1, &s, 1));
}

int	ft_put_str(char *s)
{
	int	len;

	len = 0;
	while (*s)
	{
		len += ft_put_char(*s);
		s++;
	}
	return (len);
}

int	ft_put_n_str(char *s, int n)
{
	int	len;

	if (n == -1)
		return (ft_put_str(s));
	len = 0;
	while (*s && len < n)
	{
		len += ft_put_char(*s);
		s++;
	}
	return (len);
}

int	ft_put_placeholder(t_format *format)
{
	if (format->has_zero)
		return (ft_put_char('0'));
	else
		return (ft_put_char(' '));
}

int	ft_put_placeholders(t_format *format, int quantity)
{
	int	ret;

	ret = 0;
	while (format->width > quantity)
	{
		ret += ft_put_placeholder(format);
		format->width--;
	}
	return (ret);
}
