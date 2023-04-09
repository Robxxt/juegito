#include "so_long.h"

void	move_char_horizontally(t_map *map, keys_t key)
{
	int	x;
	int	y;

	x = map->p_col;
	y = map->p_row;
	if (key == MLX_KEY_A)
	{
		if (map->matrix[y][x-1] != '1')
		{
			map->matrix[y][x] = '0';
			map->matrix[y][x-1] = 'P';
			return ;
		}
	}
	if (key == MLX_KEY_D)
	{
		if (map->matrix[y][x+1] != '1')
		{
			map->matrix[y][x] = '0';
			map->matrix[y][x+1] = 'P';
			return ;
		}
	}
}

void	move_char_vertically(t_map *map, keys_t key)
{
	int	x;
	int	y;

	x = map->p_col;
	y = map->p_row;
	if (key == MLX_KEY_W)
	{
		if (map->matrix[y-1][x] != '1')
		{
			map->matrix[y][x] = '0';
			map->matrix[y][x+1] = 'P';
			return ;
		}
	}
	if (key == MLX_KEY_S)
	{
		if (map->matrix[y+1][x] != '1')
		{
			map->matrix[y][x] = '0';
			map->matrix[y][x+1] = 'P';
			return ;
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
			move_char_vertically(data->map, keydata.key);
		if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
			move_char_horizontally(data->map, keydata.key);
	}
}