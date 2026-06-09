/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:41:53 by akurochk          #+#    #+#             */
/*   Updated: 2023/06/13 10:46:44 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putstr(char *str, int len)
{
	if (len < INT_MAX)
		write(1, str, len);
	return (len);
}

static int	ft_s(t_format *format)
{
	char	*s;
	int		len;
	size_t	s_len;

	s = "(nil)";
	len = 0;
	s_len = ft_strlen(s);
	if (format->precision >= 0 && format->precision < (int)s_len)
		s_len = format->precision;
	while (format->width > (int)s_len && !(format->align_to_left))
	{
		len += ft_put_placeholder(format);
		format->width--;
	}
	len += ft_putstr(s, s_len);
	while (format->width > (int)s_len)
	{
		len += ft_put_placeholder(format);
		format->width--;
	}
	return (len);
}

static int	put_hex(unsigned long long nmbr, int zeroes)
{
	int	len;

	len = 0;
	while (zeroes-- > 0)
		len += ft_put_char('0');
	if (nmbr / 16)
		len += put_hex((nmbr / 16), 0);
	len += ft_put_char(HEX_LOWER[nmbr % 16]);
	return (len);
}

static int	ft_p(t_format *format, unsigned long long p, int p_len, int zeroes)
{
	int	len;

	len = 0;
	while (!(format->align_to_left) && p_len < format->width)
	{
		len += ft_put_placeholder(format);
		format->width--;
	}
	if (format->precision == 0 && p == 0)
		return (len);
	while (!(format->align_to_left) && p_len < format->width)
	{
		len += ft_put_char(' ');
		format->width--;
	}
	len += ft_put_str("0x");
	len += put_hex(p, zeroes);
	while (p_len < format->width)
	{
		len += ft_put_char(' ');
		format->width--;
	}
	return (len);
}

int	ft_print_p(t_format *format, va_list list)
{
	unsigned long long	p;
	int					len;
	int					p_len;
	int					zeroes;

	len = 0;
	p = (unsigned long long)va_arg(list, void *);
	p_len = ft_count_u_digits(p, 16) + 2;
	zeroes = 0;
	if ((p_len - 1) < format->precision)
		zeroes = format->precision - (p_len - 1);
	else if (p_len < format->precision)
		zeroes = format->precision - p_len;
	p_len += zeroes;
	if (p)
		len += ft_p(format, p, p_len, zeroes);
	else
		len += ft_s(format);
	return (len);
}
