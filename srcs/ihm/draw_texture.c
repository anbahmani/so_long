/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:32:31 by abahmani          #+#    #+#             */
/*   Updated: 2021/11/28 18:37:06 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

void	draw_floor(t_ihm *data, int x, int y)
{
	t_img	floor_img;
	int		floor_width;
	int		floor_height;
	int		i;

	floor_img.img = mlx_xpm_file_to_image(data->mlx, FLOOR_TEXTURES,
			&floor_width, &floor_height);
	floor_img.colors = (int *)mlx_get_data_addr(floor_img.img,
			&(floor_img.bits_per_pixel), &(floor_img.line_length),
			&(floor_img.endian));
	floor_img.addr = mlx_get_data_addr(floor_img.img,
			&(floor_img.bits_per_pixel), &(floor_img.line_length),
			&(floor_img.endian));
	i = 0;
	while (i < HEIGHT_TEXTURES * WIDTH_TEXTURES)
	{
		my_mlx_pixel_put(&data->img, (x * 32) + (i % WIDTH_TEXTURES),
			(y * 32) + (i / WIDTH_TEXTURES), floor_img.colors[i]);
		i++;
	}
}

void	draw_player(t_ihm *data, int x, int y)
{
	t_img	player_img;
	int		player_width;
	int		player_height;
	int		i;

	player_img.img = mlx_xpm_file_to_image(data->mlx, PLAYER_TEXTURES,
			&player_width, &player_height);
	player_img.colors = (int *)mlx_get_data_addr(player_img.img,
			&(player_img.bits_per_pixel), &(player_img.line_length),
			&(player_img.endian));
	player_img.addr = mlx_get_data_addr(player_img.img,
			&(player_img.bits_per_pixel), &(player_img.line_length),
			&(player_img.endian));
	i = 0;
	while (i < HEIGHT_TEXTURES * WIDTH_TEXTURES)
	{
		my_mlx_pixel_put(&data->img, (x * 32) + (i % WIDTH_TEXTURES),
			(y * 32) + (i / WIDTH_TEXTURES), player_img.colors[i]);
		i++;
	}
}

void	draw_wall(t_ihm *data, int x, int y)
{
	t_img	wall_img;
	int		wall_width;
	int		wall_height;
	int		i;

	wall_img.img = mlx_xpm_file_to_image(data->mlx, WALL_TEXTURES,
			&wall_width, &wall_height);
	wall_img.colors = (int *)mlx_get_data_addr(wall_img.img,
			&(wall_img.bits_per_pixel), &(wall_img.line_length),
			&(wall_img.endian));
	wall_img.addr = mlx_get_data_addr(wall_img.img,
			&(wall_img.bits_per_pixel), &(wall_img.line_length),
			&(wall_img.endian));
	i = 0;
	while (i < HEIGHT_TEXTURES * WIDTH_TEXTURES)
	{
		my_mlx_pixel_put(&data->img, (x * 32) + (i % WIDTH_TEXTURES),
			(y * 32) + (i / WIDTH_TEXTURES), wall_img.colors[i]);
		i++;
	}
}

void	draw_collectible(t_ihm *data, int x, int y)
{
	t_img	collectible_img;
	int		collectible_width;
	int		collectible_height;
	int		i;

	collectible_img.img = mlx_xpm_file_to_image(data->mlx, COLLECTIBLE_TEXTURES,
			&collectible_width, &collectible_height);
	collectible_img.colors = (int *)mlx_get_data_addr(collectible_img.img,
			&(collectible_img.bits_per_pixel), &(collectible_img.line_length),
			&(collectible_img.endian));
	collectible_img.addr = mlx_get_data_addr(collectible_img.img,
			&(collectible_img.bits_per_pixel), &(collectible_img.line_length),
			&(collectible_img.endian));
	i = 0;
	while (i < HEIGHT_TEXTURES * WIDTH_TEXTURES)
	{
		my_mlx_pixel_put(&data->img, (x * 32) + (i % WIDTH_TEXTURES),
			(y * 32) + (i / WIDTH_TEXTURES), collectible_img.colors[i]);
		i++;
	}
}

void	draw_exit(t_ihm *data, int x, int y)
{
	t_img	draw_img;
	int		draw_width;
	int		draw_height;
	int		i;

	draw_img.img = mlx_xpm_file_to_image(data->mlx, EXIT_TEXTURES,
			&draw_width, &draw_height);
	draw_img.colors = (int *)mlx_get_data_addr(draw_img.img,
			&(draw_img.bits_per_pixel), &(draw_img.line_length),
			&(draw_img.endian));
	draw_img.addr = mlx_get_data_addr(draw_img.img,
			&(draw_img.bits_per_pixel), &(draw_img.line_length),
			&(draw_img.endian));
	i = 0;
	while (i < HEIGHT_TEXTURES * WIDTH_TEXTURES)
	{
		my_mlx_pixel_put(&data->img, (x * 32) + (i % WIDTH_TEXTURES),
			(y * 32) + (i / WIDTH_TEXTURES), draw_img.colors[i]);
		i++;
	}
}
