/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:09:17 by abahmani          #+#    #+#             */
/*   Updated: 2021/12/04 18:56:01 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map_data	map;
	t_ihm		data;

	map.map = check_error(ac, av, &check_authorized_char);
	if (map.map == NULL)
		return (1);
	map.width = (int)ft_strlen((char const *)map.map[0]);
	map.height = (int)count_str((char const **)map.map);
	get_player_position(&map);
	init_ihm(&map, &data);
	return (0);
}
