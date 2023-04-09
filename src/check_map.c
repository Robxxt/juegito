/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:32:25 by rdragan           #+#    #+#             */
/*   Updated: 2023/04/09 18:35:44 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	set_map_attr_to_zero(t_map *map)
{
	map->main_chars = 0;
	map->comestibles = 0;
	map->exits = 0;
}

void	count_chars(t_map *map, int i, int j)
{
	if (map->matrix[i][j] == 'P')
	{
		map->p_row = i;
		map->p_col = j;
		map->main_chars++;
	}
	if (map->matrix[i][j] == 'E')
	{
		map->e_row = i;
		map->e_col = j;
		map->exits++;
	}
	if (map->matrix[i][j] == 'C')
		map->comestibles++;
}

/*
Checks that the perimeter is made by walls.
*/
void	check_perimeter(t_map *map)
{
	int	i;
	int	j;

	set_map_attr_to_zero(map);
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (is_perimeter(i, j, map->height, map->width) == 0
				&& map->matrix[i][j] != '1')
				handle_error("Invalid map. Invalid wall perimeter!");
			else
				count_chars(map, i, j);
		}
	}
	if (map->main_chars != 1 || map->exits != 1
		|| map->comestibles < 1)
		handle_error("Invalid number of main_chars, exits or comestibles!");
}

void	check_map(t_map *map, char *filename)
{
	check_perimeter(map);
	verify_valid_path(map, filename);
}
