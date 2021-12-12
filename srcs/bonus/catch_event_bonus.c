/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_event_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 19:48:39 by abahmani          #+#    #+#             */
/*   Updated: 2021/12/11 11:20:16 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

void	sprite_movement(t_bonus *bonus)
{
	static int	time = 0;
	int			i;
	int			j;

	i = 0;
	if ((time % 50) == 0)
	{
		bonus->gold.curr = (bonus->gold.curr + 1) % 7;
		while (bonus->engine->map->map[++i] != NULL)
		{
			j = 0;
			while (bonus->engine->map->map[i][++j])
			{
				if (bonus->engine->map->map[i][j] == 'C')
				{
					draw_text(bonus->engine->data, j, i,
						bonus->gold.tab[bonus->gold.curr]);
				}
			}
		}
		time = 0;
	}
	time++;
}

static int	exposure_events(t_bonus *bonus)
{
	char	*str_nb_move;
	
	sprite_movement(bonus);
	monster_movement(bonus);
	mlx_put_image_to_window(bonus->engine->data->mlx,
		bonus->engine->data->mlx_win, bonus->engine->data->img.img, 0, 0);
	str_nb_move = ft_itoa(bonus->engine->nb_move);
	mlx_string_put(bonus->engine->data->mlx, bonus->engine->data->mlx_win,
		0, 10, 0x00FFFF, str_nb_move);
	free(str_nb_move);
	return (1);
}

int	move_bonus(t_bonus *bonus, int pos_x, int pos_y)
{
	if (bonus->engine->map->map[pos_y][pos_x] == '1')
		return (0);
	if (bonus->engine->map->map[pos_y][pos_x] == '0'
		|| bonus->engine->map->map[pos_y][pos_x] == 'C')
	{
		bonus->engine->map->map[pos_y][pos_x] = 'P';
		bonus->engine->map
			->map[bonus->engine->map->player.y][bonus->engine
			->map->player.x] = '0';
	}
	else if ((bonus->engine->map->map[pos_y][pos_x] == 'E'
		&& !still_no_collectible(bonus->engine->map->map))
		|| bonus->engine->map->map[pos_y][pos_x] == 'M')
		return (finish(bonus, bonus->engine->map->map[pos_y][pos_x]));
	else if (bonus->engine->map->map[pos_y][pos_x] == 'E')
		return (1);
	draw_text(bonus->engine->data, bonus->engine->map->player.x,
		bonus->engine->map->player.y, FLOOR_TEXTURE);
	draw_text(bonus->engine->data, pos_x, pos_y, PLAYER_TEXTURE);
	bonus->engine->map->player.x = pos_x;
	bonus->engine->map->player.y = pos_y;
	return (1);
}

static int	key_event_bonus(int keycode, t_bonus *bonus)
{
	if (keycode == KEY_W)
		move_bonus(bonus, bonus->engine->map->player.x,
			bonus->engine->map->player.y - 1);
	else if (keycode == KEY_D)
		move_bonus(bonus, bonus->engine->map->player.x + 1,
			bonus->engine->map->player.y);
	else if (keycode == KEY_S)
		move_bonus(bonus, bonus->engine->map->player.x,
			bonus->engine->map->player.y + 1);
	else if (keycode == KEY_A)
		move_bonus(bonus, bonus->engine->map->player.x - 1,
			bonus->engine->map->player.y);
	else if (keycode == KEY_ESC)
		end_game_bonus(bonus);
	mlx_put_image_to_window(bonus->engine->data->mlx,
		bonus->engine->data->mlx_win, bonus->engine->data->img.img, 0, 0);
	bonus->engine->nb_move++;
	return (0);
}

void	catch_event_bonus(t_bonus *bonus)
{
	mlx_hook(bonus->engine->data->mlx_win, 2, 1L << 0, key_event_bonus, bonus);
	mlx_hook(bonus->engine->data->mlx_win, 17, 1L << 2, mouse_event, bonus);
	mlx_loop_hook(bonus->engine->data->mlx, exposure_events, bonus);
	mlx_loop(bonus->engine->data->mlx);
}
