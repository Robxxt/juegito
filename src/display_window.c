/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 23:48:03 by rdragan           #+#    #+#             */
/*   Updated: 2023/04/09 19:51:40 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_img(mlx_t *mlx, t_image *img, t_texture *texture)
{
	mlx_delete_image(mlx, img->comestible);
	mlx_delete_image(mlx, img->main_char);
	mlx_delete_image(mlx, img->exit);
	mlx_delete_image(mlx, img->wall);
	mlx_delete_texture(texture->comestible);
	mlx_delete_texture(texture->main_char);
	mlx_delete_texture(texture->exit);
	mlx_delete_texture(texture->wall);
}

void	display_map(t_map *map, mlx_t *mlx, t_image *img)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->matrix[i][j] == '1')
				mlx_image_to_window(mlx, img->wall, j * 32, i * 32);
			if (map->matrix[i][j] == '0')
				mlx_image_to_window(mlx, img->floor, j * 32, i * 32);
			if (map->matrix[i][j] == 'P')
				mlx_image_to_window(mlx, img->main_char, j * 32, i * 32);
			if (map->matrix[i][j] == 'E')
				mlx_image_to_window(mlx, img->exit, j * 32, i * 32);
			if (map->matrix[i][j] == 'C')
				mlx_image_to_window(mlx, img->comestible, j * 32, i * 32);
		}
	}
}

void	display_window(t_map *map)
{
	mlx_t		*mlx;
	t_keyhook	hook_data;
	t_texture	texture;
	t_image		image;

	hook_data.map = map;
	mlx = mlx_init(map->width * 32, map->height * 32, "Eat the World!", true);
	if (!mlx)
		handle_error("Failed to create the window!");
	get_textrues(&texture);
	get_images(&image, &texture, mlx);
	hook_data.mlx = mlx;
	hook_data.img = &image;
	mlx_key_hook(mlx, &get_keystroke_hook, &hook_data);
	display_map(map, mlx, &image);
	mlx_loop(mlx);
	free_img(mlx, &image, &texture);
	mlx_terminate(mlx);
}
