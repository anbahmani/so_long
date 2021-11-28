/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ihm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:37:35 by abahmani          #+#    #+#             */
/*   Updated: 2021/11/28 17:52:18 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IHM_H
# define IHM_H

# include "so_long.h"
# include "img.h"

typedef struct s_ihm
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
}	t_ihm;

void	init_ihm(t_map_data map, t_ihm *data);
void	draw_map(t_map_data map, t_ihm *data);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	draw_floor(t_ihm *data, int x, int y);
void	draw_player(t_ihm *data, int x, int y);
void	draw_wall(t_ihm *data, int x, int y);
void	draw_collectible(t_ihm *data, int x, int y);
void	draw_exit(t_ihm *data, int x, int y);

#endif