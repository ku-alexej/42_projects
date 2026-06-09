/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:50:15 by akurochk          #+#    #+#             */
/*   Updated: 2023/12/18 17:07:13 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_close(void *params)
{
	t_fdf	*fdf;
	int		x;
	int		y;

	fdf = (t_fdf *)params;
	free(fdf->camera);
	y = -1;
	while (++y < fdf->map->height)
	{
		x = -1;
		while (++x < fdf->map->width)
			free(fdf->map->array[y][x]);
		free(fdf->map->array[y]);
	}
	free(fdf->map->array);
	free(fdf->map);
	mlx_destroy_image(fdf->mlx, fdf->img);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	free(fdf);
	exit(EXIT_SUCCESS);
}

void	ft_hook(t_fdf *fdf)
{
	mlx_hook(fdf->win, KeyPress, KeyPressMask, ft_key_press, fdf);
	mlx_hook(fdf->win, DestroyNotify, StructureNotifyMask, ft_close, fdf);
}
