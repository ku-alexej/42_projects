/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:41:40 by akurochk          #+#    #+#             */
/*   Updated: 2023/06/13 10:45:35 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_u_int(unsigned int nmbr, int zeroes)
{
	int	len;

	len = 0;
	while (zeroes-- > 0)
		len += ft_put_char('0');
	if (nmbr / 10)
		len += ft_put_u_int((nmbr / 10), 0);
	len += ft_put_char('0' + (nmbr % 10));
	return (len);
}

static int	ft_u(t_format *format, unsigned int u, int u_len, int zeroes)
{
	int	len;

	len = 0;
	while (!(format->align_to_left) && u_len < format->width)
	{
		len += ft_put_placeholder(format);
		format->width--;
	}
	if (!(format->precision == 0 && u == 0))
		len += ft_put_u_int(u, zeroes);
	while (u_len < format->width)
	{
		len += ft_put_char(' ');
		format->width--;
	}
	return (len);
}

int	ft_print_u(t_format *format, va_list list)
{
	unsigned int	u;
	int				len;
	int				u_len;
	int				zeroes;

	len = 0;
	u = va_arg(list, unsigned int);
	u_len = ft_count_u_digits(u, 10);
	if (format->precision == 0 && u == 0)
		u_len = 0;
	zeroes = 0;
	if (u_len < format->precision)
		zeroes = format->precision - u_len;
	u_len += zeroes;
	len += ft_u(format, u, u_len, zeroes);
	return (len);
}
