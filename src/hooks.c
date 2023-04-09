/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:22:43 by rdragan           #+#    #+#             */
/*   Updated: 2023/04/09 19:43:36 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_char_horizontally(mlx_t *mlx, t_map *map, t_image *img, int dir)
{
	int	x;
	int	y;

	x = map->p_col;
	y = map->p_row;
	if (map->matrix[y][x + dir] != '1')
	{
		mlx_image_to_window(mlx, img->floor,
			map->p_col * 32, map->p_row * 32);
		map->p_col = x + dir;
		mlx_image_to_window(mlx, img->main_char,
			map->p_col * 32, map->p_row * 32);
		if (dir == -1)
			puts("<LEFT");
		else
			puts("RIGHT>");
	}
}

void	move_char_vertically(mlx_t *mlx, t_map *map, t_image *img, int dir)
{
	int	x;
	int	y;

	x = map->p_col;
	y = map->p_row;
	if (map->matrix[y + dir][x] != '1')
	{
		mlx_image_to_window(mlx, img->floor, map->p_col * 32, map->p_row * 32);
		map->p_row = y + dir;
		mlx_image_to_window(mlx, img->main_char,
			map->p_col * 32, map->p_row * 32);
		if (dir == -1)
			puts("UP^");
		else
			puts("DOWN");
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
		if (keydata.key == MLX_KEY_W)
			move_char_vertically(data->mlx, data->map, data->img, -1);
		if (keydata.key == MLX_KEY_S)
			move_char_vertically(data->mlx, data->map, data->img, +1);
		if (keydata.key == MLX_KEY_A)
			move_char_horizontally(data->mlx, data->map, data->img, -1);
		if (keydata.key == MLX_KEY_D)
			move_char_horizontally(data->mlx, data->map, data->img, 1);
	}
}
