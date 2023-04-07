#include "so_long.h"

/*
Checks if the current postion is actually
part of the perimeter.
If true, returns 0. Else 1.
*/
int	is_perimeter(int y, int x, int map_height, int map_width)
{
	if (y == 0 || y == map_height - 1)
		return (0);
	if (x == 0 || x == map_width - 1)
		return (0);
	return (1);
}

/*
Checks that the perimeter is made by walls.
*/
void	check_perimeter(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (is_perimeter(i, j, map->height, map->width) == 0 && map->matrix[i][j] != '1')
				handle_error("Invalid map. Invalid wall perimeter!");
		}
	}

}

void	check_map(t_map *map)
{
	check_perimeter(map);
	// printf("HI THErE! %s", map->matrix[0]);
}
