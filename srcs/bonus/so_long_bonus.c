/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 19:01:05 by abahmani          #+#    #+#             */
/*   Updated: 2021/12/05 18:16:37 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

int	end_game_bonus(t_bonus	*bonus)
{
	free_mlx(bonus->engine);
	free_tab(bonus->gold.tab);
	exit(0);
}

static t_gold	*get_collectible_tab()
{
	t_gold	*gold;
	char	**tab;
	
	tab = malloc(sizeof(char *) * 8);
	if (!tab)
		return (NULL);
	tab[0] = ft_strdup(GOLD0_TEXTURE);
	tab[1] = ft_strdup(GOLD1_TEXTURE);
	tab[2] = ft_strdup(GOLD2_TEXTURE);
	tab[3] = ft_strdup(GOLD3_TEXTURE);
	tab[4] = ft_strdup(GOLD4_TEXTURE);
	tab[5] = ft_strdup(GOLD5_TEXTURE);
	tab[6] = ft_strdup(GOLD6_TEXTURE);
	tab[7] = ft_strdup(GOLD7_TEXTURE);
	gold = malloc(sizeof(t_gold));
	if (!gold)
		return (NULL);
	gold->tab = tab;
	gold->curr = 0;
	return (gold);
}

static void	draw_map_bonus(t_map_data map, t_ihm *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			draw_text(data, x, y, get_path_bonus(map.map[y][x]));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
}

static void	init_ihm_bonus(t_map_data *map, t_ihm *data)
{
	t_data	engine;
	t_gold	*gold;
	t_bonus	bonus;

	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, map->width * WIDTH_TEXTURES,
			map->height * HEIGHT_TEXTURES, "My game");
	data->img.img = mlx_new_image(data->mlx, map->width * WIDTH_TEXTURES,
			map->height * HEIGHT_TEXTURES);
	data->img.addr = mlx_get_data_addr(data->img.img,
			&(data->img.bits_per_pixel), &(data->img.size_line),
			&(data->img.endian));
	engine.map = map;
	engine.data = data;
	engine.nb_move = 0;
	check_text_file_error_bonus(&engine);
	gold = get_collectible_tab();
	if (gold == NULL)
		return; //quitter le jeu proprement
	draw_map_bonus(*map, data);
	bonus.engine = &engine;
	bonus.gold = *gold;
	catch_event_bonus(&bonus);
}

int	main(int ac, char **av)
{
	t_map_data	map;
	t_ihm		data;

	map.map = check_error(ac, av, &check_authorized_char_bonus);
	if (map.map == NULL)
		return (1);
	map.width = (int)ft_strlen((char const *)map.map[0]);
	map.height = (int)count_str((char const **)map.map);
	get_player_position(&map);
	init_ihm_bonus(&map, &data);
	return (0);
}