/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_upper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:41:25 by akurochk          #+#    #+#             */
/*   Updated: 2023/09/26 14:38:48 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_hex_upper(unsigned int nmbr, int zeroes)
{
	int	len;

	len = 0;
	while (zeroes-- > 0)
		len += ft_put_char('0');
	if (nmbr / 16)
		len += put_hex_upper((nmbr / 16), 0);
	len += ft_put_char(HEX_UPPER[nmbr % 16]);
	return (len);
}

static int	ft_x_upper(t_format *format, unsigned int u, int u_len, int zeroes)
{
	int	len;

	len = 0;
	while (!(format->align_to_left) && u_len < format->width)
	{
		len += ft_put_placeholder(format);
		format->width--;
	}
	if (!(format->precision == 0 && u == 0))
	{	
		if (format->has_sharp)
		{
			len += ft_put_str("0X");
			format->width -= 2;
		}
		len += put_hex_upper(u, zeroes);
	}
	while (u_len < format->width)
	{
		len += ft_put_placeholder(format);
		format->width--;
	}
	return (len);
}

int	ft_print_x_upper(t_format *format, va_list list)
{
	unsigned int	u;
	int				len;
	int				u_len;
	int				zeroes;

	len = 0;
	u = va_arg(list, unsigned int);
	u_len = ft_count_digits(u, 16);
	if (format->has_sharp && u)
		u_len += 2;
	if (!u)
		format->has_sharp = 0;
	if (format->precision == 0 && u == 0)
		u_len = 0;
	zeroes = 0;
	if (u_len < format->precision)
		zeroes = format->precision - u_len;
	u_len += zeroes;
	len += ft_x_upper(format, u, u_len, zeroes);
	return (len);
}
