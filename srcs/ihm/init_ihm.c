/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ihm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:30:26 by abahmani          #+#    #+#             */
/*   Updated: 2021/11/27 15:43:33 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

void	init_ihm(t_map_data map, t_ihm *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, map.width * 32,
			map.height * 32, "My game");
}