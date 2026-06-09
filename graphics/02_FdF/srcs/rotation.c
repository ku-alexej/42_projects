/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:00:15 by akurochk          #+#    #+#             */
/*   Updated: 2023/12/18 17:12:44 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom(int key, t_fdf *fdf)
{
	if (key == XK_z)
		fdf->camera->zoom += 3;
	else if (key == XK_x)
		fdf->camera->zoom -= 3;
	if (fdf->camera->zoom < 1)
		fdf->camera->zoom = 1;
}

static void	ft_rotate_y(int key, t_fdf *fdf)
{
	if (key == XK_a)
		fdf->camera->y_angle -= 0.05;
	else if (key == XK_d)
		fdf->camera->y_angle += 0.05;
}

static void	ft_rotate_x(int key, t_fdf *fdf)
{
	if (key == XK_w)
		fdf->camera->x_angle -= 0.05;
	else if (key == XK_s)
		fdf->camera->x_angle += 0.05;
}

static void	ft_rotate_z(int key, t_fdf *fdf)
{
	if (key == XK_q)
		fdf->camera->z_angle -= 0.05;
	else if (key == XK_e)
		fdf->camera->z_angle += 0.05;
}

void	ft_rotate(int key, t_fdf *fdf)
{
	if (key == XK_a || key == XK_d)
		ft_rotate_y(key, fdf);
	else if (key == XK_w || key == XK_s)
		ft_rotate_x(key, fdf);
	else if (key == XK_q || key == XK_e)
		ft_rotate_z(key, fdf);
}
