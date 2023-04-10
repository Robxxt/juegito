/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 11:19:54 by rdragan           #+#    #+#             */
/*   Updated: 2023/04/10 13:07:41 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_textrues(t_texture *texture)
{
	texture->main_char = mlx_load_xpm42("./assets/main.xpm42");
	texture->comestible = mlx_load_xpm42("./assets/comestible_01.xpm42");
	texture->floor = mlx_load_xpm42("./assets/floor.xpm42");
	texture->wall = mlx_load_xpm42("./assets/wall.xpm42");
	texture->exit = mlx_load_xpm42("./assets/exit.xpm42");
	if (!texture->exit || !texture->main_char || !texture->comestible
		|| !texture->floor || !texture->wall)
	{
		mlx_delete_xpm42(texture->comestible);
		mlx_delete_xpm42(texture->main_char);
		mlx_delete_xpm42(texture->exit);
		mlx_delete_xpm42(texture->wall);
		handle_error("Faild to take the textures assets");
	}
}

void	get_images(t_image *image, t_texture *texture, mlx_t *mlx)
{
	image->main_char = mlx_texture_to_image(mlx, &texture->main_char->texture);
	image->comestible = mlx_texture_to_image(mlx, &texture->comestible->texture);
	image->exit = mlx_texture_to_image(mlx, &texture->exit->texture);
	image->wall = mlx_texture_to_image(mlx, &texture->wall->texture);
	image->floor = mlx_texture_to_image(mlx, &texture->floor->texture);
	if (!image->exit || !image->main_char || !image->comestible
		|| !image->floor || !image->wall)
	{
		mlx_delete_image(mlx, image->comestible);
		mlx_delete_image(mlx, image->main_char);
		mlx_delete_image(mlx, image->exit);
		mlx_delete_image(mlx, image->wall);
		handle_error("Faild to take the images assets");
	}
}
