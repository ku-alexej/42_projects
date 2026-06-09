/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:59:04 by akurochk          #+#    #+#             */
/*   Updated: 2023/06/13 10:45:00 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_digits(long long nmbr, int base)
{
	int		count;

	count = 1;
	if (nmbr < 0)
	{
		nmbr *= -1;
		count++;
	}
	if (nmbr / base)
		count += ft_count_digits(nmbr / base, base);
	return (count);
}

int	ft_count_u_digits(unsigned long long nmbr, int base)
{
	int		count;

	count = 1;
	if (nmbr / base)
		count += ft_count_digits(nmbr / base, base);
	return (count);
}
