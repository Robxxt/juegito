#include "so_long.h"

void	get_keystroke_hook(mlx_key_data_t keydata, void *param)
{
	t_keyhook	*data;

	data = (t_keyhook *) param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS && data->map->p_row > 1)
	{
		data->map->p_row -= 1;
		ft_putnbr_fd(data->map->p_row, 1);
		ft_putchar_fd('\n', 1);
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS && data->map->p_row < data->map->height - 2)
	{
		data->map->p_row += 1;
		ft_putnbr_fd(data->map->p_row, 1);
		ft_putchar_fd('\n', 1);
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS && data->map->p_col > 1)
	{
		data->map->p_col -= 1;
		ft_putnbr_fd(data->map->p_col, 1);
		ft_putchar_fd('\n', 1);
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS && data->map->p_col < data->map->width - 2)
	{
		data->map->p_col += 1;
		ft_putnbr_fd(data->map->p_col, 1);
		ft_putchar_fd('\n', 1);
	}
}