/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:54:05 by akurochk          #+#    #+#             */
/*   Updated: 2023/12/19 16:05:33 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_map
{
	int	height;
	int	width;
	int	***array;
	int	z_max;
	int	z_min;
}				t_map;

typedef struct s_camera
{
	double	x_angle;
	double	y_angle;
	double	z_angle;
	int		x_move;
	int		y_move;
	int		zoom;
	float	z_scale;
	int		isometric;
}				t_camera;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data_addr;
	int			lang;
	int			bpp;
	int			size_line;
	int			endian;
	int			steep;
	t_map		*map;
	t_camera	*camera;
}				t_fdf;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
	int	reverse;
}				t_point;

unsigned int	ft_atoi_hex(const char *str);
int				ft_get_width(char *filename);
int				ft_get_height(char *filename);
void			ft_draw_all(t_map *map, t_fdf *fdf);
void			ft_draw_instructions(t_fdf *fdf);
void			ft_draw_line(t_point s, t_point e, t_fdf *fdf);
void			ft_error(const char *msg);
int				ft_calc_color(int z, t_map *map);
void			ft_parse_map(char *filename, t_map *map);
t_point			ft_point(int x, int y, t_fdf *fdf);
void			ft_put_pixel(t_fdf *fdf, int x, int y, int color);

int				ft_close(void *params);
void			ft_hook(t_fdf *fdf);
int				ft_key_press(int key, void *params);
void			ft_lang(t_fdf *fdf);
void			ft_rotate(int key, t_fdf *fdf);
void			ft_zoom(int key, t_fdf *fdf);

float			ft_abs(float n);
int				ft_ipart(float n);
float			ft_fpart(float n);
float			ft_rfpart(float n);
int				ft_min(int a, int b);

#endif
