/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 23:48:03 by rdragan           #+#    #+#             */
/*   Updated: 2023/04/09 12:07:57 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_map(t_map *map, mlx_t *mlx, t_image *img)
{
	int i;
	int j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->matrix[i][j] == '1')
				mlx_image_to_window(mlx, img->wall,  j * 32, i * 32);
			if (map->matrix[i][j] == '0')
				mlx_image_to_window(mlx, img->floor,  j * 32, i * 32);
			if (map->matrix[i][j] == 'P')
				mlx_image_to_window(mlx, img->main_char,  j * 32, i * 32);
			if (map->matrix[i][j] == 'E')
				mlx_image_to_window(mlx, img->exit,  j * 32, i * 32);
			if (map->matrix[i][j] == 'C')
				mlx_image_to_window(mlx, img->comestible,  j * 32, i * 32);
		}
	}
	printf("\nDimesions > Height: %d\twdith: %d\n", map->height, map->width);
}

void	display_window(t_map *map)
{
	mlx_t	*mlx;
	t_keyhook	hook_data;
	t_texture	texture;
	t_image		image;

	hook_data.map = map;
	mlx = mlx_init(map->width * 32, map->height * 32, "HI THERE!", true);
	if (!mlx)
		handle_error("Failed to create the window!");
	hook_data.mlx = mlx;
	mlx_key_hook(mlx, &get_keystroke_hook, &hook_data);
	printf("\nHeight: %d\twdith: %d\n", map->height, map->width);
	
	get_textrues(&texture);
	get_images(&image, &texture, mlx);
	display_map(map, mlx, &image);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}