/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:09:40 by abahmani          #+#    #+#             */
/*   Updated: 2021/11/29 21:10:33 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

int	key_events(int keycode, t_data *engine)
{
	if (keycode == KEY_W)
		up_move(engine);
	else if (keycode == KEY_D)
		right_move(engine);
	else if (keycode == KEY_S)
		down_move(engine);
	else if (keycode == KEY_A)
		left_move(engine);
	else if (keycode == KEY_ESC)
		quit(engine);
}

int mouse_event(t_data *engine)
{
	quit(engine);
}

void	catch_event(t_data *engine)
{
	mlx_hook(engine->data->mlx_win, 2, 1L<<0, key_events, &engine);
	mlx_hook(engine->data->mlx_win, 17, 1L<<2, mouse_event, &engine);
	mlx_loop(engine->data->mlx);
}
