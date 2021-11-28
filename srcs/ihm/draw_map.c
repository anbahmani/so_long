/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:40:13 by abahmani          #+#    #+#             */
/*   Updated: 2021/11/28 18:51:26 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

void	draw_map(t_map_data map, t_ihm *data)
{
	int	x;
	int	y;
(void)data;
	y = 0;
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			if (map.map[y][x] == '1')
			 	draw_wall(data, x, y);
			else if (map.map[y][x] == '0')
			 	draw_floor(data, x, y);
			else if (map.map[y][x] == 'C')
			 	draw_collectible(data, x, y);
			else if (map.map[y][x] == 'P')
			 	draw_player(data, x, y);
			else if (map.map[y][x] == 'E')
				draw_exit(data, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
}