/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:49:50 by akurochk          #+#    #+#             */
/*   Updated: 2023/12/19 14:06:47 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_reset(t_fdf *fdf)
{
	fdf->camera->x_move = 0;
	fdf->camera->y_move = 0;
	if (fdf->camera->isometric)
	{
		fdf->camera->x_angle = -0.610865;
		fdf->camera->y_angle = -0.523599;
		fdf->camera->z_angle = 0.610865;
	}
	else
	{
		fdf->camera->x_angle = -0.523599;
		fdf->camera->y_angle = -0.261799;
		fdf->camera->z_angle = 0;
	}
	fdf->camera->z_scale = 5;
	fdf->camera->zoom = ft_min(WIDTH / fdf->map->width / 2,
			HEIGHT / fdf->map->height / 2);
}

static void	ft_change_projections(t_fdf *fdf)
{
	if (fdf->camera->isometric)
	{
		fdf->camera->x_angle = -0.523599;
		fdf->camera->y_angle = -0.261799;
		fdf->camera->z_angle = 0;
	}
	else
	{
		fdf->camera->x_angle = -0.610865;
		fdf->camera->y_angle = -0.523599;
		fdf->camera->z_angle = 0.610865;
	}
	fdf->camera->isometric = !fdf->camera->isometric;
}

static void	ft_scale(int key, t_fdf *fdf)
{
	if (key == XK_minus)
		fdf->camera->z_scale += 0.1;
	else if (key == XK_equal)
		fdf->camera->z_scale -= 0.1;
	if (fdf->camera->z_scale < 0.1)
		fdf->camera->z_scale = 0.1;
	else if (fdf->camera->z_scale > 10)
		fdf->camera->z_scale = 10;
}

static void	ft_move(int key, t_fdf *fdf)
{
	if (key == XK_Up)
		fdf->camera->y_move -= 10;
	else if (key == XK_Down)
		fdf->camera->y_move += 10;
	else if (key == XK_Left)
		fdf->camera->x_move -= 10;
	else if (key == XK_Right)
		fdf->camera->x_move += 10;
}

int	ft_key_press(int key, void *params)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)params;
	if (key == XK_Up || key == XK_Down
		|| key == XK_Left || key == XK_Right)
		ft_move(key, fdf);
	else if (key == XK_w || key == XK_s
		|| key == XK_a || key == XK_d
		|| key == XK_q || key == XK_e)
		ft_rotate(key, fdf);
	else if (key == XK_z || key == XK_x)
		ft_zoom(key, fdf);
	else if (key == XK_minus || key == XK_equal)
		ft_scale(key, fdf);
	else if (key == XK_space)
		ft_change_projections(fdf);
	else if (key == XK_r)
		ft_reset(fdf);
	else if (key == XK_l)
		ft_lang(fdf);
	else if (key == XK_Escape)
		ft_close(fdf);
	ft_draw_all(fdf->map, fdf);
	return (0);
}
