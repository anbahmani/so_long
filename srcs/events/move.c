/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 23:05:24 by abahmani          #+#    #+#             */
/*   Updated: 2021/12/12 19:52:51 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	still_no_collectible(char **map)
{
	int	i;
	int	j;

	i = 1;
	while (map[i] != NULL)
	{
		j = 1;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	process_exit(t_data *engine)
{
	if (!still_no_collectible(engine->map->map))
		end_game(engine);
	return (1);
}

int	move(t_data *engine, int pos_x, int pos_y)
{
	int		x;
	int		y;

	x = engine->map->player.x;
	y = engine->map->player.y;
	if (engine->map->map[pos_y][pos_x] == '1')
		return (0);
	printf("%u\n", ++engine->nb_move);
	if (engine->map->map[pos_y][pos_x] == '0'
		|| engine->map->map[pos_y][pos_x] == 'C')
	{
		engine->map->map[pos_y][pos_x] = 'P';
		engine->map->map[y][x] = '0';
	}
	else if (engine->map->map[pos_y][pos_x] == 'E')
		return (process_exit(engine));
	draw_text(engine->data, x, y, FLOOR_TEXTURE);
	draw_text(engine->data, pos_x, pos_y, PLAYER_TEXTURE);
	engine->map->player.x = pos_x;
	engine->map->player.y = pos_y;
	return (1);
}
