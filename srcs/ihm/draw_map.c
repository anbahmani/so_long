/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:40:13 by abahmani          #+#    #+#             */
/*   Updated: 2021/12/12 19:52:51 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_text_data_addr(char *path, t_img *text_img, void *mlx)
{
	int		text_width;
	int		text_height;

	text_img->img = mlx_xpm_file_to_image(mlx, path,
			&text_width, &text_height);
	text_img->colors = (int *)mlx_get_data_addr(text_img->img,
			&(text_img->bits_per_pixel), &(text_img->size_line),
			&(text_img->endian));
	text_img->addr = mlx_get_data_addr(text_img->img,
			&(text_img->bits_per_pixel), &(text_img->size_line),
			&(text_img->endian));
}

void	draw_text(t_ihm *data, int x, int y, char *path)
{
	t_img	text_img;
	int		i;

	get_text_data_addr(path, &text_img, data->mlx);
	i = 0;
	while (i < HEIGHT_TEXTURES * WIDTH_TEXTURES)
	{
		my_mlx_pixel_put(&data->img, (x * 32) + (i % WIDTH_TEXTURES),
			(y * 32) + (i / WIDTH_TEXTURES), text_img.colors[i]);
		i++;
	}
	mlx_destroy_image(data->mlx, text_img.img);
}

void	draw_map(t_map_data map, t_ihm *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			draw_text(data, x, y, get_path(map.map[y][x]));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
}
