/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 11:19:54 by rdragan           #+#    #+#             */
/*   Updated: 2023/04/09 11:52:02 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_textrues(t_texture *texture)
{
	texture->main_char = mlx_load_png("./assets/main.png");
	texture->comestible = mlx_load_png("./assets/comestible_01.png");
	texture->floor = mlx_load_png("./assets/floor.png");
	texture->walls = mlx_load_png("./assets/wall.png");
	texture->exit = mlx_load_png("./assets/exit.png");
	if (!texture->exit || !texture->main_char || !texture->comestible
		|| !texture->floor || !texture->walls)
		handle_error("Faild to take the textures assets");
}

void	get_images(t_image *image, t_texture *texture, mlx_t *mlx)
{
	image->main_char = mlx_texture_to_image(mlx, texture->main_char);
	image->comestible = mlx_texture_to_image(mlx, texture->comestible);
	image->exit = mlx_texture_to_image(mlx, texture->exit);
	image->walls = mlx_texture_to_image(mlx, texture->walls);
	image->floor = mlx_texture_to_image(mlx, texture->floor);
	if (!image->exit || !image->main_char || !image->comestible
		|| !image->floor || !image->walls)
		handle_error("Faild to take the images assets");
}
