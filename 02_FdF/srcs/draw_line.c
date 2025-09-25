/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:50:57 by akurochk          #+#    #+#             */
/*   Updated: 2023/12/19 17:07:40 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_mix_col(int first, int second, double percent)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * percent));
}

static int	ft_get_color(int x, t_point s, t_point e, float factor)
{
	int		r;
	int		g;
	int		b;
	float	percent;

	percent = ft_abs(x - s.x) / ft_abs(e.x - s.x);
	if (s.reverse)
	{
		r = ft_mix_col((e.color >> 16) & 0xFF, (s.color >> 16) & 0xFF, percent);
		g = ft_mix_col((e.color >> 8) & 0xFF, (s.color >> 8) & 0xFF, percent);
		b = ft_mix_col(e.color & 0xFF, s.color & 0xFF, percent);
	}
	else
	{
		r = ft_mix_col((s.color >> 16) & 0xFF, (e.color >> 16) & 0xFF, percent);
		g = ft_mix_col((s.color >> 8) & 0xFF, (e.color >> 8) & 0xFF, percent);
		b = ft_mix_col(s.color & 0xFF, e.color & 0xFF, percent);
	}
	r *= factor;
	g *= factor;
	b *= factor;
	return ((r << 16) | (g << 8) | b);
}

static void	ft_swap(int *a, int *b, int *c, int *d)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	tmp = *c;
	*c = *d;
	*d = tmp;
}

static void	ft_draw_line_loop(t_point s, t_point e, float gradient, t_fdf *fdf)
{
	float	inter_y;
	int		x;

	inter_y = (float)s.y;
	x = s.x;
	while (x <= e.x)
	{
		if (fdf->steep)
		{
			ft_put_pixel(fdf, ft_ipart(inter_y), x,
				ft_get_color(x, s, e, ft_rfpart(inter_y)));
			ft_put_pixel(fdf, ft_ipart(inter_y) + 1, x,
				ft_get_color(x, s, e, ft_fpart(inter_y)));
		}
		else
		{
			ft_put_pixel(fdf, x, ft_ipart(inter_y),
				ft_get_color(x, s, e, ft_rfpart(inter_y)));
			ft_put_pixel(fdf, x, ft_ipart(inter_y) + 1,
				ft_get_color(x, s, e, ft_fpart(inter_y)));
		}
		inter_y += gradient;
		x++;
	}
}

void	ft_draw_line(t_point s, t_point e, t_fdf *fdf)
{
	float	dy;
	float	dx;
	float	gradient;

	fdf->steep = ft_abs(e.y - s.y) > ft_abs(e.x - s.x);
	if (fdf->steep)
		ft_swap(&s.x, &s.y, &e.x, &e.y);
	if (s.x > e.x)
	{
		ft_swap(&s.x, &e.x, &s.y, &e.y);
		s.reverse = 1;
	}
	dx = (float)(e.x - s.x);
	dy = (float)(e.y - s.y);
	gradient = dy / dx;
	if (dx == 0.0f)
		gradient = 1.f;
	ft_draw_line_loop(s, e, gradient, fdf);
}
