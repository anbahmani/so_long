/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ihm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:30:26 by abahmani          #+#    #+#             */
/*   Updated: 2021/11/28 14:58:03 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

void	init_ihm(t_map_data map, t_ihm *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, map.width * WIDTH_TEXTURES,
			map.height * HEIGHT_TEXTURES, "My game");
	data->img.img = mlx_new_image(data->mlx, map.width * WIDTH_TEXTURES,
			map.height * HEIGHT_TEXTURES);
	data->img.addr = mlx_get_data_addr(data->img.img,
			&(data->img.bits_per_pixel), &(data->img.line_length),
			&(data->img.endian));
	draw_map(map, data);
}