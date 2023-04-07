#include "so_long.h"

void	get_keystroke_hook(mlx_key_data_t keydata, void *param)
{
	t_map	*map;

	map = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		puts("ESCAPE!");
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS && map->p_row > 1)
	{
		map->p_row -= 1;
		ft_putnbr_fd(map->p_row, 1);
		ft_putchar_fd('\n', 1);
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS && map->p_row < map->height - 2)
	{
		map->p_row += 1;
		ft_putnbr_fd(map->p_row, 1);
		ft_putchar_fd('\n', 1);
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS && map->p_col > 1)
	{
		map->p_col -= 1;
		ft_putnbr_fd(map->p_col, 1);
		ft_putchar_fd('\n', 1);
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS && map->p_col < map->width - 2)
	{
		map->p_col += 1;
		ft_putnbr_fd(map->p_col, 1);
		ft_putchar_fd('\n', 1);
	}
}