/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ihm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:37:35 by abahmani          #+#    #+#             */
/*   Updated: 2021/12/02 20:01:13 by abahmani         ###   ########.fr       */
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

typedef struct s_data
{
	t_map_data		*map;
	t_ihm			*data;
	unsigned int	nb_move;
}	t_data;

void	init_ihm(t_map_data *map, t_ihm *data);
void	draw_map(t_map_data map, t_ihm *data);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	draw_text(t_ihm *data, int x, int y, char *path);
void	check_text_file_error(t_data *engine);

#endif