#include "so_long.h"

void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y - 1);
	flood_fill(map, x, y + 1);
}

static char	**copy_map_matirx(char *filename, int height)
{
	char	**cpy;
	int 	i;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	cpy = (char **)malloc(sizeof(char *) * (height + 1));
	if (!cpy)
		return (NULL);
	i = -1;
	while (++i < height)
		cpy[i] = get_next_line(fd);
	cpy[i] = NULL;
	close(fd);
	return (cpy);
}

void	verify_valid_path(t_map *map, char *filename)
{
	char	**map_copy;
	int		i;
	int		j;

	map_copy = copy_map_matirx(filename, map->height);
	flood_fill(map_copy, map->p_col, map->p_row);
	i = -1;
	while (map_copy[++i])
	{
		j = -1;
		while (map_copy[i][++j])
		{
			if (map_copy[i][j] != 'F' && map_copy[i][j] != '1' && map_copy[i][j] != '\n')
				handle_error("Either the comestible or exit is not reachable!");
		}
	}
	free(map_copy);
}
