/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:03:32 by akurochk          #+#    #+#             */
/*   Updated: 2023/06/13 10:43:43 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_parse_precision(t_format *format, char **ptr, va_list list)
{
	if (**ptr == '.')
	{
		while (**ptr == '.')
			(*ptr)++;
		format->precision = 0;
		if (ft_isdigit(**ptr))
		{
			format->precision = ft_atoi(*ptr);
			if (format->precision == -1)
				return (NULL);
			*ptr += ft_count_digits(format->precision, 10);
		}
		else if (**ptr == '*')
		{
			format->precision = va_arg(list, int);
			(*ptr)++;
		}
	}
	return (*ptr);
}

static char	*ft_parse_width(t_format *format, char **ptr, va_list list)
{
	if (ft_isdigit(**ptr))
	{
		format->width = ft_atoi(*ptr);
		if (format->width == -1)
			return (NULL);
		*ptr += ft_count_digits(format->width, 10);
	}
	else if (**ptr == '*')
	{
		format->width = va_arg(list, int);
		(*ptr)++;
	}
	return (*ptr);
}

static char	*ft_parse_flag(t_format *format, char **ptr)
{
	while (**ptr && ft_strchr("0+- #", **ptr))
	{
		if (**ptr == '0')
			format->has_zero = 1;
		if (**ptr == '+')
			format->has_plus = 1;
		if (**ptr == '-')
			format->align_to_left = 1;
		if (**ptr == ' ')
			format->has_space = 1;
		if (**ptr == '#')
			format->has_sharp = 1;
		(*ptr)++;
	}
	return (*ptr);
}

static void	ft_set_default(t_format *format)
{
	format->type = 0;
	format->has_plus = 0;
	format->has_space = 0;
	format->has_zero = 0;
	format->has_sharp = 0;
	format->width = -1;
	format->precision = -1;
	format->align_to_left = 0;
}

char	*ft_parse_format(t_format *format, char *ptr, va_list list)
{
	ptr++;
	ft_set_default(format);
	ptr = ft_parse_flag(format, &ptr);
	ptr = ft_parse_width(format, &ptr, list);
	if (!ptr)
		return (NULL);
	ptr = ft_parse_precision(format, &ptr, list);
	if (!ptr)
		return (NULL);
	if (format->has_plus)
		format->has_space = 0;
	if (format->align_to_left || format->precision >= 0)
		format->has_zero = 0;
	if (*ptr && ft_strchr("cspdiuxX%", *ptr))
	{
		format->type = *ptr;
		return (++ptr);
	}
	return (ptr);
}
