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
	int		fd;

	if (argc != 2)
		handle_error("Invalid number of arguments!");
	fd = file_checker(argv[1]);
	map = get_map(fd);
	printf("%d %d\n", map->height, map->width);
	return (0);
}
