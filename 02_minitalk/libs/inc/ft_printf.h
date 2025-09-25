/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:43:29 by akurochk          #+#    #+#             */
/*   Updated: 2023/09/26 16:41:23 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

typedef struct s_format
{
	int	type;
	int	has_plus;
	int	has_space;
	int	has_zero;
	int	has_sharp;
	int	width;
	int	precision;
	int	align_to_left;
}	t_format;

int		ft_printf(const char *str, ...);
char	*ft_parse_format(t_format *format, char *ptr, va_list list);
int		ft_print_c(t_format *format, va_list list);
int		ft_print_s(t_format *format, va_list list);
int		ft_print_p(t_format *format, va_list list);
int		ft_print_d(t_format *format, va_list list);
int		ft_print_u(t_format *format, va_list list);
int		ft_print_x_lower(t_format *format, va_list list);
int		ft_print_x_upper(t_format *format, va_list list);
int		ft_print_percent(t_format *format);

//-----utils-----//
int		ft_put_char(char c);
int		ft_put_str(char *s);
int		ft_put_n_str(char *s, int n);
int		ft_put_placeholder(t_format *format);
int		ft_put_placeholders(t_format *format, int quantity);
int		ft_count_digits(long long nmbr, int base);
int		ft_count_u_digits(unsigned long long nmbr, int base);

#endif
