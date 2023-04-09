/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:22:43 by rdragan           #+#    #+#             */
/*   Updated: 2023/04/09 18:31:01 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_char_horizontally(mlx_t *mlx, t_map *map, keys_t key, t_image *img)
{
	int	x;
	int	y;

	x = map->p_col;
	y = map->p_row;
	if (key == MLX_KEY_A)
	{
		if (map->matrix[y][x-1] != '1')
		{
			mlx_image_to_window(mlx, img->floor, map->p_col * 32, map->p_row * 32);
			map->p_col = x-1;
			puts("<LEFT");
			mlx_image_to_window(mlx, img->main_char, map->p_col * 32, map->p_row * 32);
		}
	}
	if (key == MLX_KEY_D)
	{
		if (map->matrix[y][x+1] != '1')
		{
			mlx_image_to_window(mlx, img->floor, map->p_col * 32, map->p_row * 32);
			map->p_col = x+1;
			puts("RIGHT>");
			mlx_image_to_window(mlx, img->main_char, map->p_col * 32, map->p_row * 32);
		}
	}
}

void	move_char_vertically(mlx_t *mlx, t_map *map, keys_t key, t_image *img)
{
	int	x;
	int	y;

	x = map->p_col;
	y = map->p_row;
	if (key == MLX_KEY_W)
	{
		if (map->matrix[y-1][x] != '1')
		{
			mlx_image_to_window(mlx, img->floor, map->p_col * 32, map->p_row * 32);
			map->p_row = y-1;
			puts("UP^");
			mlx_image_to_window(mlx, img->main_char, map->p_col * 32, map->p_row * 32);
		}
	}
	if (key == MLX_KEY_S)
	{
		if (map->matrix[y+1][x] != '1')
		{
			mlx_image_to_window(mlx, img->floor, map->p_col * 32, map->p_row * 32);
			map->p_row = y+1;
			puts("DOWN");
			mlx_image_to_window(mlx, img->main_char, map->p_col * 32, map->p_row * 32);
		}
	}
}

void	get_keystroke_hook(mlx_key_data_t keydata, void *param)
{
	t_keyhook	*data;

	data = (t_keyhook *) param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S)
			move_char_vertically(data->mlx, data->map, keydata.key, data->img);
		if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
			move_char_horizontally(data->mlx, data->map, keydata.key, data->img);

	}
}