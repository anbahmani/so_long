/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textureUtils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 00:32:11 by abahmani          #+#    #+#             */
/*   Updated: 2021/12/12 19:52:51 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	return (EXIT_TEXTURE);
}
