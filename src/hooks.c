/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:22:43 by rdragan           #+#    #+#             */
/*   Updated: 2023/04/10 14:46:36 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Handle when finds comestible, space or exit.
If the char is C or 0 returns 1;
If is E returns 2.
*/
int	handle_char(t_map *map, int x, int y)
{
	if (map->matrix[y][x] == 'C')
	{
		map->comestible_achieved++;
		map->matrix[y][x] = '0';
		ft_putstr_fd("GOT COMESTIBLE!\n", 1);
		return (1);
	}
	if (map->matrix[y][x] == 'E')
		return (2);
	return (1);
}

void	move_char_horizontally(mlx_t *mlx, t_map *map, t_image *img, int dir)
{
	int	x;
	int	y;

	x = map->p_col;
	y = map->p_row;
	if (map->matrix[y][x + dir] != '1')
	{
		if (handle_char(map, x + dir, y) == 1)
		{
			mlx_image_to_window(mlx, img->floor,
				map->p_col * 32, map->p_row * 32);
			map->p_col = x + dir;
			mlx_image_to_window(mlx, img->main_char,
				map->p_col * 32, map->p_row * 32);
			if (dir == -1)
				ft_putstr_fd("<LEFT\n", 1);
			else
				ft_putstr_fd("RIGHT>\n", 1);
		}
		else if (map->comestible_achieved == map->comestibles)
		{
			ft_putstr_fd("YOU WIN!\n", 1);
			mlx_close_window(mlx);
		}
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
		if (handle_char(map, x, y + dir) == 1)
		{
			mlx_image_to_window(mlx, img->floor,
				map->p_col * 32, map->p_row * 32);
			map->p_row = y + dir;
			mlx_image_to_window(mlx, img->main_char,
				map->p_col * 32, map->p_row * 32);
			if (dir == -1)
				ft_putstr_fd("<LEFT\n", 1);
			else
				ft_putstr_fd("RIGHT>\n", 1);
		}
		else if (map->comestible_achieved == map->comestibles)
		{
			ft_putstr_fd("YOU WIN!\n", 1);
			mlx_close_window(mlx);
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
