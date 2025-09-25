/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:43:05 by akurochk          #+#    #+#             */
/*   Updated: 2023/06/13 10:47:22 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(t_format *format, va_list list)
{
	char	c;
	int		len;

	c = va_arg(list, int);
	len = 0;
	while (!(format->align_to_left) && format->width > 1)
	{
		len += ft_put_char(' ');
		format->width--;
	}
	len += ft_put_char(c);
	while (format->width > 1)
	{
		len += ft_put_char(' ');
		format->width--;
	}
	return (len);
}
