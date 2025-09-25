/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:50:47 by akurochk          #+#    #+#             */
/*   Updated: 2023/12/18 18:20:46 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_all(t_map *map, t_fdf *fdf)
{
	int	x;
	int	y;

	ft_bzero(fdf->data_addr, WIDTH * HEIGHT * (fdf->bpp / 8));
	y = 0;
	if (fdf->camera->x_angle > 0)
		y = map->height - 1;
	while (y < map->height && y >= 0)
	{
		x = 0;
		if (fdf->camera->y_angle > 0)
			x = map->width - 1;
		while (x < map->width && x >= 0)
		{
			if (x != map->width - 1)
				ft_draw_line(ft_point(x, y, fdf), ft_point(x + 1, y, fdf), fdf);
			if (y != map->height - 1)
				ft_draw_line(ft_point(x, y, fdf), ft_point(x, y + 1, fdf), fdf);
			x += -2 * (fdf->camera->y_angle > 0) + 1;
		}
		y += -2 * (fdf->camera->x_angle > 0) + 1;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	ft_draw_instructions(fdf);
}
