/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:51:27 by akurochk          #+#    #+#             */
/*   Updated: 2023/12/19 15:54:05 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_rotate_x(int *y, int *z, double x_angle)
{
	int	buff_y;

	buff_y = *y;
	*y = buff_y * cos(x_angle) + *z * sin(x_angle);
	*z = buff_y * -sin(x_angle) + *z * cos(x_angle);
}

static void	ft_rotate_y(int *x, int *z, double y_angle)
{
	int	buff_x;

	buff_x = *x;
	*x = buff_x * cos(y_angle) + *z * sin(y_angle);
	*z = buff_x * -sin(y_angle) + *z * cos(y_angle);
}

static void	ft_rotate_z(int *x, int *y, double z_angle)
{
	t_point	buff;

	buff.x = *x;
	buff.y = *y;
	*x = buff.x * cos(z_angle) - buff.y * sin(z_angle);
	*y = buff.x * sin(z_angle) + buff.y * cos(z_angle);
}

t_point	ft_point(int x, int y, t_fdf *fdf)
{
	t_point	point;

	point.z = fdf->map->array[y][x][0];
	if (fdf->map->array[y][x][1] >= 0)
		point.color = fdf->map->array[y][x][1];
	else
		point.color = ft_calc_color(fdf->map->array[y][x][0], fdf->map);
	point.x = x * fdf->camera->zoom;
	point.y = y * fdf->camera->zoom;
	point.z *= fdf->camera->zoom / fdf->camera->z_scale;
	point.x -= (fdf->map->width * fdf->camera->zoom) / 2;
	point.y -= (fdf->map->height * fdf->camera->zoom) / 2;
	ft_rotate_x(&point.y, &point.z, fdf->camera->x_angle);
	ft_rotate_y(&point.x, &point.z, fdf->camera->y_angle);
	ft_rotate_z(&point.x, &point.y, fdf->camera->z_angle);
	point.x += WIDTH / 2 + fdf->camera->x_move;
	point.y += (HEIGHT + fdf->map->height / 2 * fdf->camera->zoom) / 2
		+ fdf->camera->y_move;
	point.reverse = 0;
	return (point);
}
