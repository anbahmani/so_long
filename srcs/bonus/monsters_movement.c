/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monsters_movement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:21:47 by abahmani          #+#    #+#             */
/*   Updated: 2021/12/07 13:37:40 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

static void	exchange_text(t_pos monster, int f_x, int f_y, t_bonus *bonus)
{
	draw_text(bonus->engine->data, monster.x, monster.y, FLOOR_TEXTURE);
	draw_text(bonus->engine->data, f_x, f_y, MONSTER_TEXTURE);
	bonus->engine->map->map[f_y][f_x] = 'M';
	bonus->engine->map->map[monster.y][monster.x] = '0';
	if (!get_player_position(bonus->engine->map))
		finish(bonus, 'M');
	mlx_put_image_to_window(bonus->engine->data->mlx,
		bonus->engine->data->mlx_win, bonus->engine->data->img.img, 0, 0);
}

static void	make_move_less_range(int x, int y, t_bonus *bonus, double less_r)
{
	t_pos	p;
	t_pos	monster;

	p.x = bonus->engine->map->player.x;
	p.y = bonus->engine->map->player.y;
	monster.x = x;
	monster.y = y;
	if (less_r == range(monster.x, monster.y + 1, p.x, p.y)
		&& is_player_space(bonus->engine->map->map, x, y + 1))
		exchange_text(monster, monster.x, monster.y + 1, bonus);
	else if (less_r == range(monster.x, monster.y - 1, p.x, p.y)
		&& is_player_space(bonus->engine->map->map, x, y - 1))
		exchange_text(monster, monster.x, monster.y - 1, bonus);
	else if (less_r == range(monster.x + 1, monster.y, p.x, p.y)
		&& is_player_space(bonus->engine->map->map, x + 1, y))
		exchange_text(monster, monster.x + 1, monster.y, bonus);
	else if (less_r == range(monster.x - 1, monster.y, p.x, p.y)
		&& is_player_space(bonus->engine->map->map, x - 1, y))
		exchange_text(monster, monster.x - 1, monster.y, bonus);
}

static void	make_monster_move(int y, int x, t_bonus *bonus)
{
	double	less_range;
	int		player_x;
	int		player_y;

	player_x = bonus->engine->map->player.x;
	player_y = bonus->engine->map->player.y;
	less_range = range(x, y, player_x, player_y);
	if (is_player_space(bonus->engine->map->map, x, y + 1)
		&& range(x, y + 1, player_x, player_y) <= less_range)
		less_range = range(x, y + 1, player_x, player_y);
	else if (is_player_space(bonus->engine->map->map, x, y - 1)
			&& range(x, y - 1, player_x, player_y) <= less_range)
		less_range = range(x, y - 1, player_x, player_y);
	else if (is_player_space(bonus->engine->map->map, x + 1, y)
			&& range(x + 1, y, player_x, player_y) <= less_range)
		less_range = range(x + 1, y, player_x, player_y);
	else if (is_player_space(bonus->engine->map->map, x - 1, y)
			&& range(x - 1, y, player_x, player_y) <= less_range)
		less_range = range(x - 1, y, player_x, player_y);
	make_move_less_range(x, y, bonus, less_range);
}

int	count_monsters(char **map)
{
	int	cmp;
	int	i;
	int	j;

	cmp = 0;
	i = 1;
	while (map[i] != NULL)
	{
		j = 1;
		while (map[i][j])
		{
			if (map[i][j] == 'M')
				cmp++;
			j++;
		}
		i++;
	}
	return (cmp);
}

void	monster_movement(t_bonus *bonus)
{
	static int	time = 0;
	int			i;
	t_pos		*m_tab;

	i = 0;
	if ((time % VITESSE) == 0)
	{
		m_tab = get_monsters_pos(bonus);
		while (i < bonus->nb_monsters)
		{
			if (range(m_tab[i].x, m_tab[i].y, bonus->engine->map->player.x,
					bonus->engine->map->player.y) < 5.0)
				make_monster_move(m_tab[i].y, m_tab[i].x, bonus);
			i++;
		}
		time = 0;
		free(m_tab);
	}
	time++;
}
