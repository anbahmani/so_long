/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:09:40 by abahmani          #+#    #+#             */
/*   Updated: 2021/12/05 13:55:08 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

static int	key_event(int keycode, t_data *engine)
{
	if (keycode == KEY_W)
		move(engine, engine->map->player.x, engine->map->player.y - 1);
	else if (keycode == KEY_D)
		move(engine, engine->map->player.x + 1, engine->map->player.y);
	else if (keycode == KEY_S)
		move(engine, engine->map->player.x, engine->map->player.y + 1);
	else if (keycode == KEY_A)
		move(engine, engine->map->player.x - 1, engine->map->player.y);
	else if (keycode == KEY_ESC)
		end_game(engine);
	mlx_put_image_to_window(engine->data->mlx, engine->data->mlx_win,
		engine->data->img.img, 0, 0);
	return (0);
}

int	mouse_event(t_data *engine)
{
	end_game(engine);
	return (0);
}

void	catch_event(t_data *engine)
{
	mlx_hook(engine->data->mlx_win, 2, 1L << 0, key_event, engine);
	mlx_hook(engine->data->mlx_win, 17, 1L << 2, mouse_event, engine);
	mlx_loop(engine->data->mlx);
}
