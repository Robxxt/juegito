#include <stdio.h>
#include "so_long.h"

void	handle_error(char *str)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		handle_error("Invalid number of arguments!");
	file_checker(argv[1]);
	map = get_map(argv[1]);
	for (int i = 0; i < map->height; i++)
		printf("%s", map->matrix[i]);
	return (0);
}
