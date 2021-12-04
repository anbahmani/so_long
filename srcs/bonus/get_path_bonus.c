/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 19:30:26 by abahmani          #+#    #+#             */
/*   Updated: 2021/12/04 19:30:42 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

char	*get_path(char c)
{
	if (c == '1')
		return (WALL_TEXTURE);
	if (c == '0')
		return (FLOOR_TEXTURE);
	if (c == 'P')
		return (PLAYER_TEXTURE);
	if (c == 'C')
		return (COLLECTIBLE_TEXTURE);
	if (c == 'E')
		return (EXIT_TEXTURE);
	return (MONSTER_TEXTURE);
}