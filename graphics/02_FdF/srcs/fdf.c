/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:53:22 by akurochk          #+#    #+#             */
/*   Updated: 2023/12/19 14:06:11 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_fdf	*ft_init_fdf(const char *path)
{
	t_fdf	*fdf;
	char	*title;

	title = ft_strjoin("FdF - ", path);
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		ft_error("Error: malloc");
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		ft_error("Error: mlx init");
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, title);
	if (!fdf->win)
		ft_error("Error: window init");
	free(title);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->img)
		ft_error("Error: image init");
	fdf->data_addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->size_line,
			&fdf->endian);
	fdf->lang = 1;
	fdf->map = NULL;
	fdf->camera = NULL;
	return (fdf);
}

static t_map	*ft_init_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		ft_error("Error: malloc");
	map->height = 0;
	map->width = 0;
	map->array = NULL;
	map->z_max = 0;
	map->z_min = 0;
	return (map);
}

static t_camera	*ft_init_camera(t_fdf *fdf)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		ft_error("Error: malloc");
	camera->zoom = ft_min(WIDTH / fdf->map->width / 2,
			HEIGHT / fdf->map->height / 2);
	camera->x_angle = -0.610865;
	camera->y_angle = -0.523599;
	camera->z_angle = 0.610865;
	camera->z_scale = 5;
	camera->x_move = 0;
	camera->y_move = 0;
	camera->isometric = 1;
	return (camera);
}

int	main(int ac, char *av[])
{
	t_fdf	*fdf;

	if (ac != 2)
	{
		ft_putendl_fd("Try: ./fdf <filename>", STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
	fdf = ft_init_fdf(av[1]);
	fdf->map = ft_init_map();
	ft_parse_map(av[1], fdf->map);
	fdf->camera = ft_init_camera(fdf);
	ft_hook(fdf);
	ft_draw_all(fdf->map, fdf);
	mlx_loop(fdf->mlx);
}
