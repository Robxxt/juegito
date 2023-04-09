/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:32:44 by rdragan           #+#    #+#             */
/*   Updated: 2023/04/09 18:38:55 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	return (len);
}

static void	check_valid_characters(char *str, char *s)
{
	int	i;
	int	len;

	i = 0;
	len = get_strlen(str);
	while (i < len)
	{
		if (!ft_strchr(s, str[i]))
			handle_error("Invalid Character!");
		i++;
	}
}

static void	get_dimensions(char *filename, t_map *map)
{
	char	*tmp;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		handle_error("Can't open the file!");
	tmp = get_next_line(fd);
	map->width = get_strlen(tmp);
	map->height = 0;
	while (tmp)
	{
		check_valid_characters(tmp, "01CEP");
		if (map->width != get_strlen(tmp))
			handle_error("Invalid map dimesions");
		map->height++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	if (map->height < 3 || map->width < 3)
		handle_error("Invalid map dimesions");
}

char	**get_matrix(char *filename, t_map *map)
{
	char	**map_matrix;
	int		i;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		handle_error("Can't open the file!");
	map_matrix = malloc((map->height + 1) * sizeof(char *));
	if (!map_matrix)
		return (NULL);
	i = -1;
	while (++i < map->height)
	{
		map_matrix[i] = get_next_line(fd);
	}
	map_matrix[i] = NULL;
	close(fd);
	return (map_matrix);
}

t_map	*get_map(char *filename)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	get_dimensions(filename, map);
	map->matrix = get_matrix(filename, map);
	return (map);
}
