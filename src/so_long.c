/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:22:58 by rdragan           #+#    #+#             */
/*   Updated: 2023/04/09 18:32:51 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		handle_error("Invalid number of arguments!");
	file_checker(argv[1]);
	map = get_map(argv[1]);
	check_map(map, argv[1]);
	display_window(map);
	free_t_map(map);
	return (0);
}
