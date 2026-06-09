/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:43:38 by akurochk          #+#    #+#             */
/*   Updated: 2023/06/13 10:46:28 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_in_format(t_format *format, va_list list)
{
	if (format->type == 'c')
		return (ft_print_c(format, list));
	if (format->type == 's')
		return (ft_print_s(format, list));
	if (format->type == 'p')
		return (ft_print_p(format, list));
	if (format->type == 'd')
		return (ft_print_d(format, list));
	if (format->type == 'i')
		return (ft_print_d(format, list));
	if (format->type == 'u')
		return (ft_print_u(format, list));
	if (format->type == 'x')
		return (ft_print_x_lower(format, list));
	if (format->type == 'X')
		return (ft_print_x_upper(format, list));
	if (format->type == '%')
		return (ft_print_percent(format));
	return (0);
}

static int	ft_start_print(char *ptr, va_list list)
{
	t_format	format;
	int			add_len;
	int			len;

	len = 0;
	while (*ptr && len < INT_MAX)
	{
		if (*ptr == '%')
		{
			ptr = ft_parse_format(&format, ptr, list);
			if (!ptr)
				return (-1);
			add_len = ft_print_in_format(&format, list);
			if (len + add_len >= INT_MAX)
				return (-1);
			len += add_len;
			continue ;
		}
		len += ft_put_char(*ptr);
		ptr++;
	}
	if (len == INT_MAX)
		return (-1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	char	*ptr;
	int		len;

	ptr = (char *)str;
	va_start(list, str);
	len = ft_start_print(ptr, list);
	va_end(list);
	return (len);
}
