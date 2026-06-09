/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:51:20 by akurochk          #+#    #+#             */
/*   Updated: 2023/12/19 16:01:31 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_fill_table(int **n, char *line, int width)
{
	char	**num;
	int		i;
	int		j;

	num = ft_split(line, ' ');
	i = -1;
	while (num[++i] && i < width)
	{
		n[i] = malloc(sizeof(int) * 2);
		if (!n[i])
			ft_error("Error: malloc");
		n[i][0] = ft_atoi(num[i]);
		j = 0;
		while (num[i][j] && num[i][j] != ',')
			j++;
		if (num[i][j] == ',')
			n[i][1] = ft_atoi_hex(&num[i][++j]);
		else
			n[i][1] = -1;
		free(num[i]);
	}
	if (i != width || num[i])
		ft_error("Error: incorrect map");
	free(num);
}

static void	ft_get_z_min_max(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->z_min = map->array[0][0][0];
	map->z_max = map->array[0][0][0];
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->array[i][j][0] < map->z_min)
				map->z_min = map->array[i][j][0];
			if (map->array[i][j][0] > map->z_max)
				map->z_max = map->array[i][j][0];
			j++;
		}
		i++;
	}
}

static void	ft_parse_map_start(char *filename, t_map *map)
{
	map->width = ft_get_width(filename);
	map->height = ft_get_height(filename);
		map->array = malloc(sizeof(int **) * map->height);
	if (!map->array)
		ft_error("Error: malloc");
}

void	ft_parse_map(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	int		i;

	ft_parse_map_start(filename, map);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error("Error: open file");
	i = -1;
	line = get_next_line(fd);
	while (line)
	{
		map->array[++i] = malloc(sizeof(int *) * map->width);
		if (!map->array[i])
			ft_error("Error: malloc");
		ft_fill_table(map->array[i], line, map->width);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	ft_get_z_min_max(map);
	if (close(fd) == -1)
		ft_error("Error: close file");
}
