/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monsters_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 00:53:21 by abahmani          #+#    #+#             */
/*   Updated: 2021/12/12 19:52:51 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_player_space(char **map, int x, int y)
{
	if (map[y][x] == '0' || map[y][x] == 'P')
		return (1);
	return (0);
}

static	void	get_monster_pos_bis(t_pos index, t_pos *tab, int cmp)
{
	t_pos	m;

	m.x = index.x;
	m.y = index.y;
	tab[cmp] = m;
}

t_pos	*get_monsters_pos(t_bonus *bonus)
{
	t_pos	*tab;
	t_pos	index;
	int		cmp;

	index.y = 0;
	cmp = 0;
	tab = malloc(sizeof(t_pos) * bonus->nb_monsters);
	if (!tab)
		return (NULL);
	while (bonus->engine->map->map[++index.y])
	{
		index.x = 0;
		while (bonus->engine->map->map[index.y][++index.x])
		{
			if (bonus->engine->map->map[index.y][index.x] == 'M')
				get_monster_pos_bis(index, tab, cmp++);
			if (cmp == bonus->nb_monsters)
				return (tab);
		}
	}
	return (NULL);
}
