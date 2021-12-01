/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:09:17 by abahmani          #+#    #+#             */
/*   Updated: 2021/12/01 14:41:58 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	end_game(t_data *engine)
{
	free_mlx(engine);
	exit(0);
}

int	main(int ac, char **av)
{
	t_map_data	map;
	t_ihm		data;
	
	map.map = check_error(ac, av);
	if (map.map == NULL)
		return (1);
	map.width = (int)ft_strlen((char const *)map.map[0]);
	map.height = (int)count_str((char const **)map.map);
	get_player_position(&map);
	init_ihm(&map, &data);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img.img, 0, 0);
	mlx_loop(data.mlx);
	free_tab(map.map);
	return (0);
}
