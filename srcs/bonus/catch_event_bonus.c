/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_event_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 19:48:39 by abahmani          #+#    #+#             */
/*   Updated: 2021/12/06 01:22:27 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

static void	print_map(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_putstr_fd(tab[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}

int	finish(t_bonus *bonus, char c)
{
	if (c == 'E')
		printf("Bravo ! Vous avez gagne !\n");
	else if (c == 'M')
		printf("Dommage ... Vous avez perdu.\n");
	return (end_game_bonus(bonus));
}

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
	print_map(bonus->engine->map->map);
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
		&& bonus->engine->map->map[monster.y + 1][monster.x] == '0')
		exchange_text(monster, monster.x, monster.y + 1, bonus);
	else if (less_r == range(monster.x, monster.y - 1, p.x, p.y)
				&& bonus->engine->map->map[monster.y - 1][monster.x] == '0')
		exchange_text(monster, monster.x, monster.y - 1, bonus);
	else if (less_r == range(monster.x + 1, monster.y, p.x, p.y)
				&& bonus->engine->map->map[monster.y][monster.x + 1] == '0')
		exchange_text(monster, monster.x + 1, monster.y, bonus);
	else if (less_r == range(monster.x - 1, monster.y, p.x, p.y)
				&& bonus->engine->map->map[monster.y][monster.x - 1] == '0')
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
	if (bonus->engine->map->map[y + 1][x] == '0'
		&& range(x, y + 1, player_x, player_y) <= less_range)
		less_range = range(x, y + 1, player_x, player_y);
	else if (bonus->engine->map->map[y - 1][x] == '0'
			&& range(x, y - 1, player_x, player_y) <= less_range)
		less_range = range(x, y - 1, player_x, player_y);
	else if (bonus->engine->map->map[y][x + 1] == '0'
			&& range(x + 1, y, player_x, player_y) <= less_range)
		less_range = range(x + 1, y, player_x, player_y);
	else if (bonus->engine->map->map[y][x - 1] == '0'
			&& range(x - 1, y, player_x, player_y) <= less_range)
		less_range = range(x - 1, y, player_x, player_y);
	make_move_less_range(x, y, bonus,less_range);
}

int count_monsters(char **map)
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
	if ((time % 50) == 0)
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

static int	exposure_events(t_bonus *bonus)
{
	sprite_movement(bonus);
	monster_movement(bonus);
	mlx_put_image_to_window(bonus->engine->data->mlx,
		bonus->engine->data->mlx_win, bonus->engine->data->img.img, 0, 0);
	mlx_string_put(bonus->engine->data->mlx, bonus->engine->data->mlx_win,
		0, 10, 0x00FFFF, ft_itoa(bonus->engine->nb_move));
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
		->map[bonus->engine->map->player.y][bonus->engine->map->player.x ] = '0';
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
