/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:23:43 by akurochk          #+#    #+#             */
/*   Updated: 2023/12/18 18:41:42 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_lang(t_fdf *fdf)
{
	if (fdf->lang)
		fdf->lang = 0;
	else
		fdf->lang = 1;
}

static void	ft_draw_en(t_fdf *fdf)
{
	int	color;

	color = 0xFFFFFF;
	mlx_string_put(fdf->mlx, fdf->win, 20, 45, color,
		"  Use keyboard to control the image");
	mlx_string_put(fdf->mlx, fdf->win, 20, 60, color,
		"  rotate:                   w, a, s, d, q, e");
	mlx_string_put(fdf->mlx, fdf->win, 20, 75, color,
		"  move:                               arrows");
	mlx_string_put(fdf->mlx, fdf->win, 20, 90, color,
		"  zoom:                                 z, x");
	mlx_string_put(fdf->mlx, fdf->win, 20, 105, color,
		"  scale:                                -, +");
	mlx_string_put(fdf->mlx, fdf->win, 20, 120, color,
		"  change projection:                   space");
	mlx_string_put(fdf->mlx, fdf->win, 20, 135, color,
		"  reset:                                   r");
	mlx_string_put(fdf->mlx, fdf->win, 20, 150, color,
		"  change language to french :              l");
	mlx_string_put(fdf->mlx, fdf->win, 20, 165, color,
		"  exit:                                  ESC");
}

static void	ft_draw_fr(t_fdf *fdf)
{
	int	color;

	color = 0xFFFFFF;
	mlx_string_put(fdf->mlx, fdf->win, 20, 45, color,
		"  Utilisez le clavier pour controler l'image");
	mlx_string_put(fdf->mlx, fdf->win, 20, 60, color,
		"  pivoter :                 w, a, s, d, q, e");
	mlx_string_put(fdf->mlx, fdf->win, 20, 75, color,
		"  bouger :                           fleches");
	mlx_string_put(fdf->mlx, fdf->win, 20, 90, color,
		"  zoomer :                              z, x");
	mlx_string_put(fdf->mlx, fdf->win, 20, 105, color,
		"  changer l'echelle :                   -, +");
	mlx_string_put(fdf->mlx, fdf->win, 20, 120, color,
		"  changer la projection :             espace");
	mlx_string_put(fdf->mlx, fdf->win, 20, 135, color,
		"  reinitialiser :                          r");
	mlx_string_put(fdf->mlx, fdf->win, 20, 150, color,
		"  changer la langue en anglais :           l");
	mlx_string_put(fdf->mlx, fdf->win, 20, 165, color,
		"  quitter:                               ESC");
}

static void	ft_draw_frame(t_fdf *fdf)
{
	int	color;
	int	y;

	color = 0x3366FF;
	y = 45;
	mlx_string_put(fdf->mlx, fdf->win, 20, 30, color,
		"o - - - - - - - - - - - - - - - - - - - - - - o");
	while (y < 180)
	{
		mlx_string_put(fdf->mlx, fdf->win, 20, y, color,
			"|                                             |");
		y += 15;
	}
	mlx_string_put(fdf->mlx, fdf->win, 20, 180, color,
		"o - - - - - - - - - - - - - - - - - - - - - - o");
}

void	ft_draw_instructions(t_fdf *fdf)
{
	if (fdf->lang)
		ft_draw_en(fdf);
	else
		ft_draw_fr(fdf);
	ft_draw_frame(fdf);
}
