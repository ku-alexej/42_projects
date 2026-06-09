/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:43:05 by akurochk          #+#    #+#             */
/*   Updated: 2023/09/26 14:38:28 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_percent(t_format *format)
{
	int	len;

	len = 0;
	while (!(format->align_to_left) && format->width > 1)
	{
		len += ft_put_placeholder(format);
		format->width--;
	}
	len += ft_put_char('%');
	while (format->width > 1)
	{
		len += ft_put_placeholder(format);
		format->width--;
	}
	return (len);
}
