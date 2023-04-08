#include <stdio.h>
#include "so_long.h"

void	handle_error(char *str)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	exit(1);
}

void	free_t_map(t_map *map)
{
	int	i;

	i = -1;
	while (map->matrix[++i])
		free(map->matrix[i]);
	free(map->matrix);
	free(map);
}

void	display_window(t_map *map)
{
	mlx_t	*mlx;
	t_keyhook	hook_data;

	hook_data.map = map;
	mlx = mlx_init(map->width * 32, map->height * 32, "HI THERE!", true);
	if (!mlx)
		handle_error("Failed to create the window!");
	hook_data.mlx = mlx;
	mlx_key_hook(mlx, &get_keystroke_hook, &hook_data);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		handle_error("Invalid number of arguments!");
	file_checker(argv[1]);
	map = get_map(argv[1]);
	check_map(map, argv[1]);
	for (int i = 0; i < map->height; i++)
		printf("%s", map->matrix[i]);
	printf("\nmain_chars: %d\texits: %d\tcomestibles: %d\n", map->main_chars, map->exits, map->comestibles);
	free_t_map(map);
	display_window(map);
	return (0);
}
