/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:42:01 by akurochk          #+#    #+#             */
/*   Updated: 2023/06/13 10:43:52 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_int(int n, int zeroes, int has_zero)
{
	int			len;
	long long	nmbr;

	len = 0;
	nmbr = n;
	if (nmbr < 0)
	{
		if (!has_zero)
			len += ft_put_char('-');
		nmbr *= -1;
	}
	while (zeroes-- > 0)
		len += ft_put_char('0');
	if (nmbr / 10)
		len += ft_put_int((int)(nmbr / 10), 0, 0);
	len += ft_put_char('0' + (nmbr % 10));
	return (len);
}

static int	ft_d(t_format *format, int d, int d_len, int zeroes)
{
	int	len;

	len = 0;
	if (format->has_zero && d < 0)
		len += ft_put_char('-');
	if (!(format->align_to_left))
		len += ft_put_placeholders(format, d_len);
	if (format->has_plus && d >= 0)
		len += ft_put_char('+');
	if (format->has_space && d >= 0)
		len += ft_put_char(' ');
	if (!(format->precision == 0 && d == 0))
		len += ft_put_int(d, zeroes, format->has_zero);
	len += ft_put_placeholders(format, d_len);
	return (len);
}

int	ft_print_d(t_format *format, va_list list)
{
	int	d;
	int	len;
	int	d_len;
	int	zeroes;

	len = 0;
	d = va_arg(list, int);
	d_len = ft_count_digits(d, 10);
	if (format->precision == 0 && d == 0)
		d_len = 0;
	zeroes = 0;
	if (d < 0 && (d_len - 1) < format->precision)
		zeroes = format->precision - (d_len - 1);
	else if (d_len < format->precision)
		zeroes = format->precision - d_len;
	d_len += zeroes;
	if (d >= 0 && (format->has_plus || format->has_space))
		format->width--;
	len += ft_d(format, d, d_len, zeroes);
	return (len);
}
