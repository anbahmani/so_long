/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_event_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 19:48:39 by abahmani          #+#    #+#             */
/*   Updated: 2021/12/04 19:58:26 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

int	exposure_event

void	catch_event_bonus(t_bonus bonus)
{
	mlx_hook(bonus.engine->data->mlx_win, 2, 1L << 0, key_event, bonus.engine);
	mlx_hook(bonus.engine->data->mlx_win, 17, 1L << 2, mouse_event,
	bonus.engine);
	mlx_hook(bonus.engine->data->mlx_win, 12, 1L << 15, exposure_event, bonus);
	mlx_loop(bonus.engine->data->mlx);
}