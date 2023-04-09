/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:43:07 by rdragan           #+#    #+#             */
/*   Updated: 2023/04/09 18:45:10 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_map
{
	char	**matrix;
	int		width;
	int		height;
	int		main_chars;
	int		p_row;
	int		p_col;
	int		comestibles;
	int		exits;
	int		e_row;
	int		e_col;
}	t_map;

typedef struct s_texture
{
	mlx_texture_t	*main_char;
	mlx_texture_t	*comestible;
	mlx_texture_t	*exit;
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
}	t_texture;

typedef struct s_image
{
	mlx_image_t	*main_char;
	mlx_image_t	*comestible;
	mlx_image_t	*exit;
	mlx_image_t	*wall;
	mlx_image_t	*floor;
}	t_image;

typedef struct s_keyhook
{
	t_map	*map;
	mlx_t	*mlx;
	t_image	*img;
}	t_keyhook;

void	handle_error(char *str);
void	file_checker(char *filename);
t_map	*get_map(char *filename);
void	check_map(t_map *map, char *filename);
void	verify_valid_path(t_map *map, char *filename);
int		is_perimeter(int y, int x, int map_height, int map_width);
void	get_keystroke_hook(mlx_key_data_t keydata, void *param);
void	display_window(t_map *map);
void	get_textrues(t_texture *texture);
void	get_images(t_image *image, t_texture *texture, mlx_t *mlx);

#endif