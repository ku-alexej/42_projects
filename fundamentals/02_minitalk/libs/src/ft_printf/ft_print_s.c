/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:42:49 by akurochk          #+#    #+#             */
/*   Updated: 2023/09/26 14:38:34 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_s(t_format *format, char *s, int print_len)
{
	int	len;

	len = 0;
	while (!(format->align_to_left) && format->width > print_len)
	{
		len += ft_put_char(' ');
		format->width--;
	}
	len += ft_put_n_str(s, print_len);
	while (format->width > print_len)
	{
		len += ft_put_char(' ');
		format->width--;
	}
	return (len);
}

int	ft_print_s(t_format *format, va_list list)
{
	char	*s;
	int		len;
	int		s_len;

	s = va_arg(list, char *);
	len = 0;
	s_len = -1;
	if (!s)
	{
		if (format->precision >= 6 || format->precision == -1)
			len += ft_s(format, "(null)", 6);
		else if (format->precision > -1 && format->precision <= 5)
			len += ft_s(format, "(null)", 0);
		else
			len += ft_s(format, "(null)", format->precision);
	}
	else
	{
		s_len = (int)ft_strlen(s);
		if ((format->precision >= s_len || format->precision == -1))
			len += ft_s(format, s, s_len);
		else
			len += ft_s(format, s, format->precision);
	}
	return (len);
}
